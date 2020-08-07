#include "mb.h"
#include "mbport.h"

#define NB_REG_INPUT_SIZE  10						///< 输入寄存器大小
uint16_t MB_REG_INPUT_BUF[NB_REG_INPUT_SIZE];		///< 输入寄存器

#define NB_REG_HOLD_SIZE  10						///< 保持寄存器大小
uint16_t MB_REG_HOLD_BUF[NB_REG_HOLD_SIZE];			///< 保持寄存器

/**
 * CMD3回调函数
 * @param  pucRegBuffer 存放读取到的输入寄存器的值
 * @param  usAddress    要读取的输入寄存器起始地址
 * @param  usNRegs      要读取的输入寄存器数量
 * @return              MB_ENOERR：成功  other：失败
 */
eMBErrorCode eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
    int iRegIndex = usAddress - 1;
	
	// 非法检测
	if((iRegIndex + usNRegs) > NB_REG_INPUT_SIZE)
	{
		return MB_ENOREG;
	}
	
	// 循环读取
	while( usNRegs > 0 )
	{
		*pucRegBuffer++ =
			( unsigned char )( MB_REG_INPUT_BUF[iRegIndex] >> 8 );
		*pucRegBuffer++ =
			( unsigned char )( MB_REG_INPUT_BUF[iRegIndex] & 0xFF );
		iRegIndex++;
		usNRegs--;
	}
	
	// 模拟输入寄存器被改变
	for(iRegIndex = 0; iRegIndex < NB_REG_INPUT_SIZE; iRegIndex++)
	{
		MB_REG_INPUT_BUF[iRegIndex]++;
	}
	
    return MB_ENOERR;
}

/**
 * CMD3回调函数
 * @param  pucRegBuffer 存放读取到的保持寄存器值
 * @param  usAddress    要读取的保持寄存器地址
 * @param  usNRegs      要读取的保持寄存器数量
 * @param  eMode        模式，读取或者写入，本例程只用了读取
 * @return              MB_ENOERR：成功  other：失败
 */
eMBErrorCode eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
    int iRegIndex = usAddress - 1;
	
	// 非法检测
	if((iRegIndex + usNRegs) > NB_REG_HOLD_SIZE)
	{
		return MB_ENOREG;
	}
	
	// 循环读取
	while( usNRegs > 0 )
	{
		*pucRegBuffer++ =
			( unsigned char )( MB_REG_HOLD_BUF[iRegIndex] >> 8 );
		*pucRegBuffer++ =
			( unsigned char )( MB_REG_HOLD_BUF[iRegIndex] & 0xFF );
		iRegIndex++;
		usNRegs--;
	}
	
	// 模拟保持寄存器被改变
	for(iRegIndex = 0; iRegIndex < NB_REG_HOLD_SIZE; iRegIndex++)
	{
		MB_REG_HOLD_BUF[iRegIndex]++;
	}
	
    return MB_ENOERR;
}

/// 未使用
eMBErrorCode eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode )
{
    return MB_ENOREG;
}

/// 未使用
eMBErrorCode eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    return MB_ENOREG;
}
