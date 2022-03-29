void main(void) // Main Function
{
     P1 = 0x00;
     while(1) 
     {
           P1 = 0xFF; 
           delay(1000);
           P1 = 0x00; 
           delay(1000);
       }
}
