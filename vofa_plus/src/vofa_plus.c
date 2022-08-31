#include <vofa_plus.h>
#include <rtthread.h>               
#include <rtdevice.h>               
#include <board.h> 
#include "stdarg.h"


#if PKG_USING_VOFA_PLUS


#ifdef BSP_USING_UART4
static rt_device_t uart4;
static struct serial_configure uart4_config = RT_SERIAL_CONFIG_DEFAULT; 
#endif


//number_of_channels 当前要显示的通道数，后面的可变参数是unsigned int 类型的通道数据，可变参数的个数与number_of_channels保持一致
char vofa_plus_transmit(vofa_plus_dev_struct_t_p dev,unsigned int number_of_channels,...)
{
    unsigned char idx;
    unsigned int val;
    va_list args;
    va_start(args, number_of_channels);

    if (number_of_channels > VOFA_PLUS_NUMBER_OF_CHANNELS)
    {
        va_end(args);
        return -1;
    }


    for (idx = 0; idx < number_of_channels; ++idx) 
    {

        val = va_arg(args, unsigned int);
        dev->tx_con_buff[idx] = val;
    }
    va_end(args);
    memcpy(dev->tx_buff, (unsigned char *)(dev->tx_con_buff), sizeof(dev->tx_con_buff));
    dev->tx_buff[VOFA_PLUS_NUMBER_OF_CHANNELS*4] = 0x00;                   
    dev->tx_buff[VOFA_PLUS_NUMBER_OF_CHANNELS*4+1] = 0x00;
    dev->tx_buff[VOFA_PLUS_NUMBER_OF_CHANNELS*4+2] = 0x80;
    dev->tx_buff[VOFA_PLUS_NUMBER_OF_CHANNELS*4+3] = 0x7f;
	#if defined( VOFA_PLUS_USING_UART1)
		#ifdef BSP_USING_UART1
		#endif
	#elif defined( VOFA_PLUS_USING_UART4)
		#ifdef BSP_USING_UART4
		rt_device_write(uart4, 0, dev->tx_buff, VOFA_PLUS_BUFSZ);
		#endif
	#endif

    return 0;
  

}





void vofa_plus_init(void)
{
	rt_err_t ret = RT_EOK;
	#ifdef BSP_USING_UART4
    uart4 = rt_device_find("uart4");
    if (!uart4)
    {
        rt_kprintf("find %s failed!\n", "uart4");
        return RT_ERROR;
    }
    uart4_config.baud_rate = BAUD_RATE_115200;            
    uart4_config.data_bits = DATA_BITS_8;                 
    uart4_config.parity = PARITY_NONE;                 
    uart4_config.stop_bits = STOP_BITS_1;                 
    uart4_config.bit_order = BIT_ORDER_LSB;              
    uart4_config.invert = NRZ_NORMAL;                 
    uart4_config.flowcontrol = RT_SERIAL_FLOWCONTROL_NONE;  
    uart4_config.bufsz = 128;                         
    uart4_config.reserved = 0;                          
    if (RT_EOK != rt_device_control(uart4, RT_DEVICE_CTRL_CONFIG, &uart4_config))
    {
        rt_kprintf("%s configuration error!\n", "uart4");
        return RT_ERROR;
    }
    rt_device_open(uart4, RT_DEVICE_FLAG_INT_TX);
	#endif
    return ret;
}



#endif









