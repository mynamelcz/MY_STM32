#include "bsp_nvic.h"
#include "stm32f4xx.h"


static void bsp_nivc_enable(u8 IRQChannel, u8 PreemptionPriority, u8 SubPriority)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PreemptionPriority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = SubPriority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
	
static void bsp_nvic_disable(u8 IRQChannel)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
	NVIC_Init(&NVIC_InitStructure);
}




#define IRQ_TAB_LEN  	100

irq_fun_t nvic_irq_tab[IRQ_TAB_LEN];

static void bsp_nvic_detach_irq_fun(u8 IRQChannel)
{
	nvic_irq_tab[IRQChannel] = NULL;
}


static void bsp_nvic_attach_irq_fun(u8 IRQChannel, irq_fun_t fun)
{
	nvic_irq_tab[IRQChannel] = fun;
}

static void bsp_nvic_init(void)
{
	for(int i = 0; i < IRQ_TAB_LEN; i++){
		nvic_irq_tab[i] = NULL;
	}
}





const bsp_nvic_t BSP_NVIC_DRV = {
	.init = bsp_nvic_init,
	.enable_irq = bsp_nivc_enable,
	.disable_irq = bsp_nvic_disable,
	.attach_fun = bsp_nvic_attach_irq_fun,
	.detach_fun = bsp_nvic_detach_irq_fun,
};


/******************************************************************/
void WWDG_IRQHandler                (void)  {  if(nvic_irq_tab[ WWDG_IRQn                   ]!=NULL){nvic_irq_tab[  WWDG_IRQn                   ]();}}                   
void PVD_IRQHandler                 (void)  {  if(nvic_irq_tab[ PVD_IRQn                    ]!=NULL){nvic_irq_tab[  PVD_IRQn                    ]();}} 
void TAMP_STAMP_IRQHandler          (void)  {  if(nvic_irq_tab[ TAMP_STAMP_IRQn             ]!=NULL){nvic_irq_tab[  TAMP_STAMP_IRQn             ]();}}
void RTC_WKUP_IRQHandler            (void)  {  if(nvic_irq_tab[ RTC_WKUP_IRQn               ]!=NULL){nvic_irq_tab[  RTC_WKUP_IRQn               ]();}}
void FLASH_IRQHandler               (void)  {  if(nvic_irq_tab[ FLASH_IRQn                  ]!=NULL){nvic_irq_tab[  FLASH_IRQn                  ]();}}                    
void RCC_IRQHandler                 (void)  {  if(nvic_irq_tab[ RCC_IRQn                    ]!=NULL){nvic_irq_tab[  RCC_IRQn                    ]();}}                       
//void EXTI0_IRQHandler               (void)  {  if(nvic_irq_tab[ EXTI0_IRQn                  ]!=NULL){nvic_irq_tab[  EXTI0_IRQn                  ]();}}                       
//void EXTI1_IRQHandler               (void)  {  if(nvic_irq_tab[ EXTI1_IRQn                  ]!=NULL){nvic_irq_tab[  EXTI1_IRQn                  ]();}}                        
//void EXTI2_IRQHandler               (void)  {  if(nvic_irq_tab[ EXTI2_IRQn                  ]!=NULL){nvic_irq_tab[  EXTI2_IRQn                  ]();}}                       
//void EXTI3_IRQHandler               (void)  {  if(nvic_irq_tab[ EXTI3_IRQn                  ]!=NULL){nvic_irq_tab[  EXTI3_IRQn                  ]();}}                      
//void EXTI4_IRQHandler               (void)  {  if(nvic_irq_tab[ EXTI4_IRQn                  ]!=NULL){nvic_irq_tab[  EXTI4_IRQn                  ]();}}                       
void DMA1_Stream0_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA1_Stream0_IRQn          ]!=NULL){nvic_irq_tab[  DMA1_Stream0_IRQn          ]();}}            
void DMA1_Stream1_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA1_Stream1_IRQn          ]!=NULL){nvic_irq_tab[  DMA1_Stream1_IRQn          ]();}}               
void DMA1_Stream2_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA1_Stream2_IRQn          ]!=NULL){nvic_irq_tab[  DMA1_Stream2_IRQn          ]();}}               
void DMA1_Stream3_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA1_Stream3_IRQn          ]!=NULL){nvic_irq_tab[  DMA1_Stream3_IRQn          ]();}}               
void DMA1_Stream4_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA1_Stream4_IRQn          ]!=NULL){nvic_irq_tab[  DMA1_Stream4_IRQn          ]();}}               
void DMA1_Stream5_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA1_Stream5_IRQn          ]!=NULL){nvic_irq_tab[  DMA1_Stream5_IRQn          ]();}}               
void DMA1_Stream6_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA1_Stream6_IRQn          ]!=NULL){nvic_irq_tab[  DMA1_Stream6_IRQn          ]();}}               
void ADC_IRQHandler                 (void)  {  if(nvic_irq_tab[ ADC_IRQn                    ]!=NULL){nvic_irq_tab[  ADC_IRQn                    ]();}}    
void CAN1_TX_IRQHandler             (void)  {  if(nvic_irq_tab[ CAN1_TX_IRQn                ]!=NULL){nvic_irq_tab[  CAN1_TX_IRQn                ]();}}                           
void CAN1_RX0_IRQHandler            (void)  {  if(nvic_irq_tab[ CAN1_RX0_IRQn               ]!=NULL){nvic_irq_tab[  CAN1_RX0_IRQn               ]();}}                          
void CAN1_RX1_IRQHandler            (void)  {  if(nvic_irq_tab[ CAN1_RX1_IRQn               ]!=NULL){nvic_irq_tab[  CAN1_RX1_IRQn               ]();}}                           
void CAN1_SCE_IRQHandler            (void)  {  if(nvic_irq_tab[ CAN1_SCE_IRQn               ]!=NULL){nvic_irq_tab[  CAN1_SCE_IRQn               ]();}}                           
//void EXTI9_5_IRQHandler             (void)  {  if(nvic_irq_tab[ EXTI9_5_IRQn                ]!=NULL){nvic_irq_tab[  EXTI9_5_IRQn                ]();}}               
void TIM1_BRK_TIM9_IRQHandler       (void)  {  if(nvic_irq_tab[ TIM1_BRK_TIM9_IRQn          ]!=NULL){nvic_irq_tab[  TIM1_BRK_TIM9_IRQn          ]();}}
//void TIM1_UP_TIM10_IRQHandler       (void)  {  if(nvic_irq_tab[ TIM1_UP_TIM10_IRQn          ]!=NULL){nvic_irq_tab[  TIM1_UP_TIM10_IRQn          ]();}}
void TIM1_TRG_COM_TIM11_IRQHandler  (void)  {  if(nvic_irq_tab[ TIM1_TRG_COM_TIM11_IRQn     ]!=NULL){nvic_irq_tab[  TIM1_TRG_COM_TIM11_IRQn     ]();}}
//void TIM1_CC_IRQHandler             (void)  {  if(nvic_irq_tab[ TIM1_CC_IRQn                ]!=NULL){nvic_irq_tab[  TIM1_CC_IRQn                ]();}}              
void TIM2_IRQHandler                (void)  {  if(nvic_irq_tab[ TIM2_IRQn                   ]!=NULL){nvic_irq_tab[  TIM2_IRQn                   ]();}}                       
void TIM3_IRQHandler                (void)  {  if(nvic_irq_tab[ TIM3_IRQn                   ]!=NULL){nvic_irq_tab[  TIM3_IRQn                   ]();}}                       
void TIM4_IRQHandler                (void)  {  if(nvic_irq_tab[ TIM4_IRQn                   ]!=NULL){nvic_irq_tab[  TIM4_IRQn                   ]();}}                       
void I2C1_EV_IRQHandler             (void)  {  if(nvic_irq_tab[ I2C1_EV_IRQn                ]!=NULL){nvic_irq_tab[  I2C1_EV_IRQn                ]();}}                        
void I2C1_ER_IRQHandler             (void)  {  if(nvic_irq_tab[ I2C1_ER_IRQn                ]!=NULL){nvic_irq_tab[  I2C1_ER_IRQn                ]();}}                        
void I2C2_EV_IRQHandler             (void)  {  if(nvic_irq_tab[ I2C2_EV_IRQn                ]!=NULL){nvic_irq_tab[  I2C2_EV_IRQn                ]();}}                       
void I2C2_ER_IRQHandler             (void)  {  if(nvic_irq_tab[ I2C2_ER_IRQn                ]!=NULL){nvic_irq_tab[  I2C2_ER_IRQn                ]();}}                          
void SPI1_IRQHandler                (void)  {  if(nvic_irq_tab[ SPI1_IRQn                   ]!=NULL){nvic_irq_tab[  SPI1_IRQn                   ]();}}                      
void SPI2_IRQHandler                (void)  {  if(nvic_irq_tab[ SPI2_IRQn                   ]!=NULL){nvic_irq_tab[  SPI2_IRQn                   ]();}}                       
void USART1_IRQHandler              (void)  {  if(nvic_irq_tab[ USART1_IRQn                 ]!=NULL){nvic_irq_tab[  USART1_IRQn                 ]();}}                     
void USART2_IRQHandler              (void)  {  if(nvic_irq_tab[ USART2_IRQn                 ]!=NULL){nvic_irq_tab[  USART2_IRQn                 ]();}}                     
void USART3_IRQHandler              (void)  {  if(nvic_irq_tab[ USART3_IRQn                 ]!=NULL){nvic_irq_tab[  USART3_IRQn                 ]();}}                    
//void EXTI15_10_IRQHandler           (void)  {  if(nvic_irq_tab[ EXTI15_10_IRQn              ]!=NULL){nvic_irq_tab[  EXTI15_10_IRQn              ]();}}             
void RTC_Alarm_IRQHandler           (void)  {  if(nvic_irq_tab[ RTC_Alarm_IRQn              ]!=NULL){nvic_irq_tab[  RTC_Alarm_IRQn              ]();}}
//void OTG_FS_WKUP_IRQHandler         (void)  {  if(nvic_irq_tab[ OTG_FS_WKUP_IRQn            ]!=NULL){nvic_irq_tab[  OTG_FS_WKUP_IRQn            ]();}}   
void TIM8_BRK_TIM12_IRQHandler      (void)  {  if(nvic_irq_tab[ TIM8_BRK_TIM12_IRQn         ]!=NULL){nvic_irq_tab[  TIM8_BRK_TIM12_IRQn         ]();}}
void TIM8_UP_TIM13_IRQHandler       (void)  {  if(nvic_irq_tab[ TIM8_UP_TIM13_IRQn          ]!=NULL){nvic_irq_tab[  TIM8_UP_TIM13_IRQn          ]();}}
void TIM8_TRG_COM_TIM14_IRQHandler  (void)  {  if(nvic_irq_tab[ TIM8_TRG_COM_TIM14_IRQn     ]!=NULL){nvic_irq_tab[  TIM8_TRG_COM_TIM14_IRQn     ]();}}
void TIM8_CC_IRQHandler             (void)  {  if(nvic_irq_tab[ TIM8_CC_IRQn                ]!=NULL){nvic_irq_tab[  TIM8_CC_IRQn                ]();}}              
void DMA1_Stream7_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA1_Stream7_IRQn          ]!=NULL){nvic_irq_tab[  DMA1_Stream7_IRQn          ]();}}                      
void FSMC_IRQHandler                (void)  {  if(nvic_irq_tab[ FSMC_IRQn                   ]!=NULL){nvic_irq_tab[  FSMC_IRQn                   ]();}}                        
void SDIO_IRQHandler                (void)  {  if(nvic_irq_tab[ SDIO_IRQn                   ]!=NULL){nvic_irq_tab[  SDIO_IRQn                   ]();}}                        
void TIM5_IRQHandler                (void)  {  if(nvic_irq_tab[ TIM5_IRQn                   ]!=NULL){nvic_irq_tab[  TIM5_IRQn                   ]();}}                        
void SPI3_IRQHandler                (void)  {  if(nvic_irq_tab[ SPI3_IRQn                   ]!=NULL){nvic_irq_tab[  SPI3_IRQn                   ]();}}                        
void UART4_IRQHandler               (void)  {  if(nvic_irq_tab[ UART4_IRQn                  ]!=NULL){nvic_irq_tab[  UART4_IRQn                  ]();}}                       
void UART5_IRQHandler               (void)  {  if(nvic_irq_tab[ UART5_IRQn                  ]!=NULL){nvic_irq_tab[  UART5_IRQn                  ]();}}                       
void TIM6_DAC_IRQHandler            (void)  {  if(nvic_irq_tab[ TIM6_DAC_IRQn               ]!=NULL){nvic_irq_tab[  TIM6_DAC_IRQn               ]();}}
void TIM7_IRQHandler                (void)  {  if(nvic_irq_tab[ TIM7_IRQn                   ]!=NULL){nvic_irq_tab[  TIM7_IRQn                   ]();}}
void DMA2_Stream0_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA2_Stream0_IRQn          ]!=NULL){nvic_irq_tab[  DMA2_Stream0_IRQn          ]();}}              
void DMA2_Stream1_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA2_Stream1_IRQn          ]!=NULL){nvic_irq_tab[  DMA2_Stream1_IRQn          ]();}}               
void DMA2_Stream2_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA2_Stream2_IRQn          ]!=NULL){nvic_irq_tab[  DMA2_Stream2_IRQn          ]();}}                
void DMA2_Stream3_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA2_Stream3_IRQn          ]!=NULL){nvic_irq_tab[  DMA2_Stream3_IRQn          ]();}}                
void DMA2_Stream4_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA2_Stream4_IRQn          ]!=NULL){nvic_irq_tab[  DMA2_Stream4_IRQn          ]();}}             
void ETH_IRQHandler                 (void)  {  if(nvic_irq_tab[ ETH_IRQn                    ]!=NULL){nvic_irq_tab[  ETH_IRQn                    ]();}}                    
void ETH_WKUP_IRQHandler            (void)  {  if(nvic_irq_tab[ ETH_WKUP_IRQn               ]!=NULL){nvic_irq_tab[  ETH_WKUP_IRQn               ]();}}
void CAN2_TX_IRQHandler             (void)  {  if(nvic_irq_tab[ CAN2_TX_IRQn                ]!=NULL){nvic_irq_tab[  CAN2_TX_IRQn                ]();}}                          
void CAN2_RX0_IRQHandler            (void)  {  if(nvic_irq_tab[ CAN2_RX0_IRQn               ]!=NULL){nvic_irq_tab[  CAN2_RX0_IRQn               ]();}}                          
void CAN2_RX1_IRQHandler            (void)  {  if(nvic_irq_tab[ CAN2_RX1_IRQn               ]!=NULL){nvic_irq_tab[  CAN2_RX1_IRQn               ]();}}                          
void CAN2_SCE_IRQHandler            (void)  {  if(nvic_irq_tab[ CAN2_SCE_IRQn               ]!=NULL){nvic_irq_tab[  CAN2_SCE_IRQn               ]();}}                          
//void OTG_FS_IRQHandler              (void)  {  if(nvic_irq_tab[ OTG_FS_IRQn                 ]!=NULL){nvic_irq_tab[  OTG_FS_IRQn                 ]();}}                  
void DMA2_Stream5_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA2_Stream5_IRQn          ]!=NULL){nvic_irq_tab[  DMA2_Stream5_IRQn          ]();}}               
void DMA2_Stream6_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA2_Stream6_IRQn          ]!=NULL){nvic_irq_tab[  DMA2_Stream6_IRQn          ]();}}               
void DMA2_Stream7_IRQHandler       (void)  {  if(nvic_irq_tab[ DMA2_Stream7_IRQn          ]!=NULL){nvic_irq_tab[  DMA2_Stream7_IRQn          ]();}}               
void USART6_IRQHandler              (void)  {  if(nvic_irq_tab[ USART6_IRQn                 ]!=NULL){nvic_irq_tab[  USART6_IRQn                 ]();}}                      
void I2C3_EV_IRQHandler             (void)  {  if(nvic_irq_tab[ I2C3_EV_IRQn                ]!=NULL){nvic_irq_tab[  I2C3_EV_IRQn                ]();}}                         
void I2C3_ER_IRQHandler             (void)  {  if(nvic_irq_tab[ I2C3_ER_IRQn                ]!=NULL){nvic_irq_tab[  I2C3_ER_IRQn                ]();}}                         
//void OTG_HS_EP1_OUT_IRQHandler      (void)  {  if(nvic_irq_tab[ OTG_HS_EP1_OUT_IRQn         ]!=NULL){nvic_irq_tab[  OTG_HS_EP1_OUT_IRQn         ]();}} 
//void OTG_HS_EP1_IN_IRQHandler       (void)  {  if(nvic_irq_tab[ OTG_HS_EP1_IN_IRQn          ]!=NULL){nvic_irq_tab[  OTG_HS_EP1_IN_IRQn          ]();}} 
//void OTG_HS_WKUP_IRQHandler         (void)  {  if(nvic_irq_tab[ OTG_HS_WKUP_IRQn            ]!=NULL){nvic_irq_tab[  OTG_HS_WKUP_IRQn            ]();}}   
//void OTG_HS_IRQHandler              (void)  {  if(nvic_irq_tab[ OTG_HS_IRQn                 ]!=NULL){nvic_irq_tab[  OTG_HS_IRQn                 ]();}}                 
void DCMI_IRQHandler                (void)  {  if(nvic_irq_tab[ DCMI_IRQn                   ]!=NULL){nvic_irq_tab[  DCMI_IRQn                   ]();}}                        
void CRYP_IRQHandler                (void)  {  if(nvic_irq_tab[ CRYP_IRQn                   ]!=NULL){nvic_irq_tab[  CRYP_IRQn                   ]();}}                
void HASH_RNG_IRQHandler            (void)  {  if(nvic_irq_tab[ HASH_RNG_IRQn               ]!=NULL){nvic_irq_tab[  HASH_RNG_IRQn               ]();}}
void FPU_IRQHandler    				(void) 	{  if(nvic_irq_tab[ FPU_IRQn                    ]!=NULL){nvic_irq_tab[  FPU_IRQn                    ]();}}






































