void StartDefaultTask(void* argument)
{
	/* USER CODE BEGIN 5 */
	/* Infinite loop */
	for (;;)
	{
		stepmotor_main();
		osDelay(1);
	}
	/* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void* argument)
{
	/* USER CODE BEGIN StartTask02 */
	/* Infinite loop */
	for (;;)
	{
		elevator_button_check();
		osDelay(1);
	}
	/* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void* argument)
{
	/* USER CODE BEGIN StartTask03 */
	/* Infinite loop */
	for (;;)
	{
		dotmatrix_main();
		fnd_time();
		osDelay(1);
	}
	/* USER CODE END StartTask03 */
}