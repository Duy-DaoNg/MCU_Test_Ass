/*
 * uart.c
 *
 *  Created on: Dec 18, 2022
 *      Author: Minh Duc Quach
 */

#include "uart.h"

//char str[30];
//void HAL_UART_RxCpltCallback ( UART_HandleTypeDef * huart ){
//	if( huart -> Instance == USART2 ) {
////		HAL_UART_Transmit (&huart1, &temp, 1, 50) ;
////		HAL_UART_Receive_IT (&huart1, &temp, 1) ;
//		HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "OK\r\n"), 1000 );
//	}
//}

//uint8_t var[30];
//uint32_t str[30];
//void uart_transmit(){
//	switch(FSM_Traffic_Light_State_Row){
//	char showTimeStamp[30] = {"_"};
//	HAL_UART_Transmit(&huart1, (void*) str, "OK\r\n", 100);
//	case AUTO_RED:
//		strcat(showTimeStamp,"A_RED: ");
//		itoa(traffic_light_remain_time_row, var, 10);
//		strcat(showTimeStamp, var);
//		strcat(showTimeStamp, "\r\n");
////		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
//		break;
//	case AUTO_GREEN:
//		strcat(showTimeStamp,"A_GREEN: ");
//		itoa(traffic_light_remain_time_row, var, 10);
//		strcat(showTimeStamp, var);
//		strcat(showTimeStamp, "\r\n");
////		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
//		break;
//	case AUTO_YEL:
//		strcat(showTimeStamp,"A_YEL: ");
//		itoa(traffic_light_remain_time_row, var, 10);
//		strcat(showTimeStamp, var);
//		strcat(showTimeStamp, "\r\n");
////		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
//		break;
//	case HAND_RED:
//		strcat(showTimeStamp,"H_RED: ");
//		itoa(traffic_light_remain_time_row, var, 10);
//		strcat(showTimeStamp, var);
//		strcat(showTimeStamp, "\r\n");
////		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
//		break;
//	case HAND_GREEN:
//		strcat(showTimeStamp,"H_GREEN: ");
//		itoa(traffic_light_remain_time_row, var, 10);
//		strcat(showTimeStamp, var);
//		strcat(showTimeStamp, "\r\n");
////		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
//		break;
//	case HAND_YEL:
//		strcat(showTimeStamp,"H_YEL: ");
//		itoa(traffic_light_remain_time_row, var, 10);
//		strcat(showTimeStamp, var);
//		strcat(showTimeStamp, "\r\n");
////		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
//		break;
//	case MANUAL_RED:
//		strcat(showTimeStamp,"M_RED: ");
//		itoa(Set_TL_Time, var, 10);
//		strcat(showTimeStamp, var);
//		strcat(showTimeStamp, "\r\n");
////		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
//		break;
//	case MANUAL_GREEN:
//		strcat(showTimeStamp,"M_GREEN: ");
//		itoa(Set_TL_Time, var, 10);
//		strcat(showTimeStamp, var);
//		strcat(showTimeStamp, "\r\n");
////		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
//		break;
//	case MANUAL_YEL:
//		strcat(showTimeStamp,"M_YEL: ");
//		itoa(Set_TL_Time, var, 10);
//		strcat(showTimeStamp, var);
//		strcat(showTimeStamp, "\r\n");
////		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
//		break;
//	default:
//		break;
//	}
//}

void uart_transmit(){
	switch(FSM_Traffic_Light_State_Row){
//		char showTimeStamp[30] = {"_"};
//		HAL_UART_Transmit(&huart1, (void*) str, "OK\r\n", 100);
		case AUTO_RED:
//			strcat(showTimeStamp,"A_RED: ");
//			itoa(traffic_light_remain_time_row, var, 10);
//			strcat(showTimeStamp, var);
//			strcat(showTimeStamp, "\r\n");
	//		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
			HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "A_RED: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case AUTO_GREEN:
//			strcat(showTimeStamp,"A_GREEN: ");
//			itoa(traffic_light_remain_time_row, var, 10);
//			strcat(showTimeStamp, var);
//			strcat(showTimeStamp, "\r\n");
	//		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
			HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "A_GREEN: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case AUTO_YEL:
//			strcat(showTimeStamp,"A_YEL: ");
//			itoa(traffic_light_remain_time_row, var, 10);
//			strcat(showTimeStamp, var);
//			strcat(showTimeStamp, "\r\n");
	//		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
			HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "A_YEL: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case HAND_RED:
//			strcat(showTimeStamp,"H_RED: ");
//			itoa(traffic_light_remain_time_row, var, 10);
//			strcat(showTimeStamp, var);
//			strcat(showTimeStamp, "\r\n");
	//		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
			HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "H_RED: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case HAND_GREEN:
//			strcat(showTimeStamp,"H_GREEN: ");
//			itoa(traffic_light_remain_time_row, var, 10);
//			strcat(showTimeStamp, var);
//			strcat(showTimeStamp, "\r\n");
	//		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
			HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "H_GREEN: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case HAND_YEL:
//			strcat(showTimeStamp,"H_YEL: ");
//			itoa(traffic_light_remain_time_row, var, 10);
//			strcat(showTimeStamp, var);
//			strcat(showTimeStamp, "\r\n");
	//		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
			HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "H_YEL: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case MANUAL_RED:
//			strcat(showTimeStamp,"M_RED: ");
//			itoa(Set_TL_Time, var, 10);
//			strcat(showTimeStamp, var);
//			strcat(showTimeStamp, "\r\n");
	//		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
			HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "M_RED: %d\r\n", Set_TL_Time), 1000 );
			break;
		case MANUAL_GREEN:
//			strcat(showTimeStamp,"M_GREEN: ");
//			itoa(Set_TL_Time, var, 10);
//			strcat(showTimeStamp, var);
//			strcat(showTimeStamp, "\r\n");
	//		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
			HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "M_GREEN: %d\r\n", Set_TL_Time), 1000 );
			break;
		case MANUAL_YEL:
//			strcat(showTimeStamp,"M_YEL: ");
//			itoa(Set_TL_Time, var, 10);
//			strcat(showTimeStamp, var);
//			strcat(showTimeStamp, "\r\n");
	//		HAL_UART_Transmit(&huart1, &showTimeStamp[0], strlen(showTimeStamp), 100);
			HAL_UART_Transmit(&huart1, (void *) str, sprintf(str, "M_YEL: %d\r\n", Set_TL_Time), 1000 );
			break;
		default:
			break;
	}
}
