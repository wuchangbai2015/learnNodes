ʹ��reStructuredText���߱�д�Լ���ѧϰ�ʼǣ��������ڱ���ʹ����ҳ�鿴

Windows��sphinx+reStructuredText�����òο����ӣ�http://www.th7.cn/system/win/201501/81743.shtml

��дubunut��Сϵͳ�õ�ָ�

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

