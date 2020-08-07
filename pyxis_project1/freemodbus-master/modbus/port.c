#include "mb.h"
#include "mbport.h"

#define NB_REG_INPUT_SIZE  10						///< ����Ĵ�����С
uint16_t MB_REG_INPUT_BUF[NB_REG_INPUT_SIZE];		///< ����Ĵ���

#define NB_REG_HOLD_SIZE  10						///< ���ּĴ�����С
uint16_t MB_REG_HOLD_BUF[NB_REG_HOLD_SIZE];			///< ���ּĴ���

/**
 * CMD3�ص�����
 * @param  pucRegBuffer ��Ŷ�ȡ��������Ĵ�����ֵ
 * @param  usAddress    Ҫ��ȡ������Ĵ�����ʼ��ַ
 * @param  usNRegs      Ҫ��ȡ������Ĵ�������
 * @return              MB_ENOERR���ɹ�  other��ʧ��
 */
eMBErrorCode eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
    int iRegIndex = usAddress - 1;
	
	// �Ƿ����
	if((iRegIndex + usNRegs) > NB_REG_INPUT_SIZE)
	{
		return MB_ENOREG;
	}
	
	// ѭ����ȡ
	while( usNRegs > 0 )
	{
		*pucRegBuffer++ =
			( unsigned char )( MB_REG_INPUT_BUF[iRegIndex] >> 8 );
		*pucRegBuffer++ =
			( unsigned char )( MB_REG_INPUT_BUF[iRegIndex] & 0xFF );
		iRegIndex++;
		usNRegs--;
	}
	
	// ģ������Ĵ������ı�
	for(iRegIndex = 0; iRegIndex < NB_REG_INPUT_SIZE; iRegIndex++)
	{
		MB_REG_INPUT_BUF[iRegIndex]++;
	}
	
    return MB_ENOERR;
}

/**
 * CMD3�ص�����
 * @param  pucRegBuffer ��Ŷ�ȡ���ı��ּĴ���ֵ
 * @param  usAddress    Ҫ��ȡ�ı��ּĴ�����ַ
 * @param  usNRegs      Ҫ��ȡ�ı��ּĴ�������
 * @param  eMode        ģʽ����ȡ����д�룬������ֻ���˶�ȡ
 * @return              MB_ENOERR���ɹ�  other��ʧ��
 */
eMBErrorCode eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
    int iRegIndex = usAddress - 1;
	
	// �Ƿ����
	if((iRegIndex + usNRegs) > NB_REG_HOLD_SIZE)
	{
		return MB_ENOREG;
	}
	
	// ѭ����ȡ
	while( usNRegs > 0 )
	{
		*pucRegBuffer++ =
			( unsigned char )( MB_REG_HOLD_BUF[iRegIndex] >> 8 );
		*pucRegBuffer++ =
			( unsigned char )( MB_REG_HOLD_BUF[iRegIndex] & 0xFF );
		iRegIndex++;
		usNRegs--;
	}
	
	// ģ�Ᵽ�ּĴ������ı�
	for(iRegIndex = 0; iRegIndex < NB_REG_HOLD_SIZE; iRegIndex++)
	{
		MB_REG_HOLD_BUF[iRegIndex]++;
	}
	
    return MB_ENOERR;
}

/// δʹ��
eMBErrorCode eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode )
{
    return MB_ENOREG;
}

/// δʹ��
eMBErrorCode eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    return MB_ENOREG;
}
