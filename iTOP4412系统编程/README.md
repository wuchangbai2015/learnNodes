һ.ʹ��ubuntuʵ�ֽ������

����ָ��Ϊ�� 

  	arm-none-linux-gnueabi-gcc -o helloword helloworld.c -static 

/****************************************************************************************/

��.��дubunut��Сϵͳ�õ�ָ�

�������񵽡�platform-tools���ļ�����

1.����ubootģʽ

�ϵ磬���������壬�����ն��У������س�������һ�ϵ�Ͱ���������ubootģʽ

2.������������ն��У��������

  	fdisk -c 0

3.��ʽ����������ն����������

  	fatformat mmc 0:1

  	ext3format mmc 0:2

  	ext3format mmc 0:3

  	ext3format mmc 0:4

4.������������ն����������

  	fastboot




��д�����windows����������:

1.��дuboot�����������д���Ѿ����ˣ���

  	fastboot.exe flash bootloader u-boot-iTOP-4412.bin

2.��дzImage�ں����

  	fastboot.exe flash kernel zImage


3.������дramdisk ����:


  	fastboot.exe flash ramdisk ramdisk-uboot.img


4.������дsystem �ļ�ϵͳ����:


  	fastboot.exe flash system system.img


����������

  	fastboot -w

�����������������

  	fastboot reboot

/****************************************************************************************/

��. ����ļ��غ�����

u�̿�����ubunut���潻������Ĵ������ص�4412��

  	mount /dev/sda1 /mnt/disk/

ж�� 

  	umount /mnt/disk/

/****************************************************************************************/

��.����ĳһ������������������ɿ���������

��helloword�ļ��ȿ�����һ��Ŀ¼�£�

  	cp -r /mut/disk /bin

  	vim /etc/init.d/rcS

��helloword�ļ�д��rcs�������

  	/bin/helloword &

/****************************************************************************************/

��.tftp�������Ĵ����Ҫ������4412�����򣬱��ڵ���

4412��ip��ַ��

  	cat /etc/eth0-setting  

ҪʹTFTP������һЩ�򵥵��ļ���4412��ubuntu pc��������ͬһ������


tftp�ļ��е�/var/tftpboot�Ƿ�������Ŀ¼����ubuntu�У���ѱ���õĶ������ļ�cp������


TFTP����Ӧ�ó���

��4412�����ϣ�

  	tftp -g -l helloworld -r helloworld + ��������ip

���磺  

  	cd /bin

  	tftp -g -l helloword -r helloword 192.168.1.104 ��192.168.1.104 ��ubuntu pc ��ip��

���У�
  
  	chmod 777 helloword 

  	./helloword


/****************************************************************************************/



