void Lcd_Address(u16 page,u16 column)
{
	column=column-0x01;
	send_cmd(0xb0+page-1);   /*����ҳ��ַ*/ //1-8
	send_cmd(0x10+(column>>4&0x0f));	/*�����е�ַ�ĸ�4λ*///0-128
	send_cmd(column&0x0f);	/*�����е�ַ�ĵ�4λ*/	
}	

