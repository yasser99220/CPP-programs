
#define UKPT_DES_BLOCK_SIZE 8
#define SESSIONID_KCV_SIZE 3

/*************************************************************************/
uchar CalculateCNA(ISecScriptCaller *pScriptCaller, uchar *CNAValue)
/*************************************************************************/
{
    uchar retv = RETV_GENERAL_ERR;
    int blockIndex;
    int no8ByteBlocks;
    uchar saveLen = 0x00;
    uchar padding[UKPT_DES_BLOCK_SIZE];
    uchar DataLen = (uchar)pScriptCaller->GetScripBufferSize();

    while (!iBucketCNA)
    {
        checkBucketCNA();
        rango::sal::Sal_Sleep(50);
    }

    memset(padding, 0x00, sizeof(padding));
    pScriptCaller->AppendToScriptBuffer(padding, sizeof(padding));

    saveLen = DataLen;
    if (DataLen % UKPT_DES_BLOCK_SIZE)
    {
        DataLen += (UKPT_DES_BLOCK_SIZE - DataLen % UKPT_DES_BLOCK_SIZE);
    }
    retv = callSecScript(SEC_SCRIPT, MACRO_CLEAR_IV, inputBufferCA, outputBufferCA);
    no8ByteBlocks = DataLen / UKPT_DES_BLOCK_SIZE;
    for (blockIndex = 0; ((blockIndex < no8ByteBlocks) && (RETV_OK == retv)); blockIndex++)
    {
        retv = pScriptCaller->CallSecScript(SEC_SCRIPT, MACRO_MAC_CALC_CNA, blockIndex * UKPT_DES_BLOCK_SIZE, UKPT_DES_BLOCK_SIZE, outputBufferCA);
    }
    if (RETV_OK == retv)
    {
        retv = callSecScript(SEC_SCRIPT, MACRO_GET_MAC_CNA, inputBufferCA, outputBufferCA);
        if (RETV_OK == retv)
        {
            pScriptCaller->PrependToScriptBuffer(outputBufferCA, UKPT_DES_BLOCK_SIZE);
            DataLen = saveLen + UKPT_DES_BLOCK_SIZE;
            inputBufferCA[0] = IX_GSALT01;
            retv = callSecScript(SEC_SCRIPT, MACRO_CHECK_KCV, inputBufferCA, outputBufferCA);
            if (RETV_OK == retv)
            {
                memcpy(CNAValue, outputBufferCA, SESSIONID_KCV_SIZE);
                pScriptCaller->CallVSS_SHA256(DataLen, &CNAValue[SESSIONID_KCV_SIZE]);
                iBucketCNA--;
            }
        }
    }
    return retv;
}

 

    //*****************************************************************************
    // MACRO_CLEAR_IV
    // Clear IV used in CBC operations
    //
    //
    MACRO 86   // Macro number 86
    CLRIV      // Clear IV
        EOM 00 // Return 0 bytes.

    //*****************************************************************************
    // MACRO_MAC_CALC_CNA
    // Generate MAC
    // Call MACRO_CLEAR_IV before first call to MACRO_MAC_CALC_CNA
    //
    // input:
    // Pos Length Mnemonic Description
    // 0   8      Data     8 bytes of data
    //
    // output
    // Pos Length Mnemonic Description
    // 0   8      encData  8 bytes of data.
    //
    MACRO 55      // Macro number 55
    GETA 00       // Copy 8 bytes from CB index 00 into reg A
    ALGO_DES56    // Select DES56.
        SELECT 36 // This selects 36 GSALT01 key.
    ECBC          // DES Encrypt CBC A with key in CK, result in A.
        EOM 00    // Return 0 bytes.

    //*****************************************************************************
    // MACRO_GET_MAC_CNA
    //
    // Get calculated MAC. MAC created using GSALT01 key.
    //
    // Call MACRO_MAC_CALC_CNA before call to MACRO_GET_MAC_CNA
    //
    // input:
    // Pos Length Mnemonic Description
    //
    // output
    // Pos Length Mnemonic Description
    // 0   8      MAC      ISO MAC using GSALT01 key
    //
    MACRO 56          // Macro number 56
    MOV_IV_A          // Copy IV to A, IV saved from last call to MACRO_MAC_CALC_CNA
        ALGO_DES56    // Select DES56.
            SELECT 37 // This selects 37 GSALT01 R as key.
    DCBC              // DES Decrypt CBC A with key in CK, result in A.
        SELECT 36     // This selects 36 GSALT01 L as key.
    ECBC              // DES Encrypt CBC A with key in CK, result in A.
        SENDA 00      // Copy A (encrypted data) to CB index 00.
    EOM 08            // Return 8 bytes.

 
    //*****************************************************************************
    // MACRO_CHECK_KCV
    // Check KCV for key in register KeyReg.
    //
    // input:
    // Pos Length Mnemonic Description
    // 0   1      KeyReg   Key register to calculate KCV for. Will asume
    //                     KeyReg+1 contains part 2 of key.
    //
    // Output:
    // Pos Length Mnemonic Description
    // 0   4      KCV      KCV for key stored in KeyReg
    //
    MACRO 81                                     // Macro number 81
    LENGTH 01                                    // Length of CB (Communication Buffer)
    GETX 00                                      // Copy KeyReg to X
    SELECTX                                      // Select key according to X (KeyReg) to CK
        CLRA                                     // Clear register A to all 0x00
            EECB                                 // DES ECB Encrypt A with key in CK, result in A.
                INCX                             // KeyReg++
                    SELECTX                      // Select key according to X (KeyReg) to CK
                        DECB                     // DES ECB Decrypt A with key in CK, result in A.
                            DECX                 // KeyReg--
                                SELECTX          // Select key according to X (KeyReg) to CK
                                    EECB         // DES ECB Encrypt A with key in CK, result in A.
                                        SENDA 00 // Copy A (encrypted data) to CB index 00.
    EOM 04                                       // Return 4 bytes.
