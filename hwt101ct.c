HAL_UART_Receive(&huart6, msg_buffer, sizeof(msg_buffer), 50);
for(int i=0; i<50; i++){
  if(msg_buffer[i]==0x55 && msg_buffer[i+1]==0x53){
    yaw_lsb  = msg_buffer[i+6];
    yaw_msb  = msg_buffer[i+7];
    yaw_data = (yaw_msb<<8)|yaw_lsb;
    yaw = yaw_data * 180.00 / 32768;
    if(yaw<0){
      yaw = 360 + yaw;
    }
    break;
  }
}
