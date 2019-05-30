//#include <stdio.h>
//#include <unistd.h>

int main()
{
	int main() {

	//Configuração inicial das portas

	// configurar entradas analógicas (necessita rodar como root)
	system("echo BB-ADC > /sys/devices/platform/bone_capemgr/slots");

	// habilitar portas do motor
	system("echo 66 > /sys/class/gpio/export");
	system("echo 67 > /sys/class/gpio/export");
	system("echo 68 > /sys/class/gpio/export");

	// habilitar portas do display
	system("echo 30 > /sys/class/gpio/export");
	system("echo 31 > /sys/class/gpio/export");
	system("echo 48 > /sys/class/gpio/export");
	system("echo 49 > /sys/class/gpio/export");
	system("echo 60 > /sys/class/gpio/export");
	system("echo 50 > /sys/class/gpio/export");
	system("echo 51 > /sys/class/gpio/export");
	system("echo 15 > /sys/class/gpio/export");

	// configurando portas do motor como saídas
	system("echo out > /sys/class/gpio/gpio66/direction");
	system("echo out > /sys/class/gpio/gpio67/direction");
	system("echo out > /sys/class/gpio/gpio68/direction");

	system("echo 1 > /sys/class/gpio/gpio68/value"); // sinal do motor -> sempre definido como 1

	// configurando portas do motor como saídas
	system("echo out > /sys/class/gpio/gpio30/direction");
	system("echo out > /sys/class/gpio/gpio31/direction");
	system("echo out > /sys/class/gpio/gpio48/direction");
	system("echo out > /sys/class/gpio/gpio49/direction");
	system("echo out > /sys/class/gpio/gpio60/direction");
	system("echo out > /sys/class/gpio/gpio50/direction");
	system("echo out > /sys/class/gpio/gpio51/direction");
	system("echo out > /sys/class/gpio/gpio15/direction");

}
