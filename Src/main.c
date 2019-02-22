/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
// #include "pymem.h"
#include "ax25.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
// UART_HandleTypeDef huart1;
// UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
#define MEM_SIZE 32000
uint8_t payload[]="HELLO WORLD";
uint8_t label[]="boiyoo";
uint8_t outbuff[255];
uint8_t size[1];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
// void SystemClock_Config(void);
// static void MX_GPIO_Init(void);
// static void MX_USART2_UART_Init(void);
// static void MX_USART1_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

// static void format_pkt(uint8_t *data, uint8_t *out, uint8_t txcnt);
// static void send_mem(void);
// static void send_pkt(uint8_t *data);

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  // HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  // /* Configure the system clock */
  // SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  // /* Initialize all configured peripherals */
  // MX_GPIO_Init();
  // MX_USART2_UART_Init();
  // MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
#if CDEV
  printf("start\n");
  creat_file();
#endif
/*
TODO:
crc
nzri
bit reverse
*/

#if DEBUG
py_cmd('p',"debug mode",sizeof("debug mode"));
#endif

  ax25_send(outbuff, payload,sizeof(payload)-1,1);
  #if CDEV
    print_file("TEST");
    data_file("ABC123");
    print_file("DEBTEST");
    printf("end");
  #endif
//   py_cmd('d',1,1);
  // size[0]=sizeof(outbuff);
  // HAL_UART_Transmit(&huart2,size,1,100);
  // HAL_Delay(100);
  // HAL_UART_Transmit(&huart2,outbuff,sizeof(outbuff),100);

/*  PACKET TESTING
  write_pkt(payload,10,sizeof(payload));
  request_pkt(recv_buffer,5,sizeof(recv_buffer));
  HAL_Delay(100);
  ser_print(recv_buffer,sizeof(recv_buffer));
*/
  /* USER CODE END 2 */

  // printf("hello world");
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  // while (1)
  // {

  /* USER CODE END WHILE */
  //HAL_UART_Receive(&huart2, num, sizeof(num), 100000);
  //num[0]++;
//  HAL_UART_Transmit(&huart2, out,sizeof(num), 100);
  /* USER CODE BEGIN 3 */

  //  }
  /* USER CODE END 3 */

}



/* USER CODE BEGIN 4 */




#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
