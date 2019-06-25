# Sistema de distribuição de frenagem

Leonardo Simião de Luna 8006032

Flavio Tarciso Ronchi 9311692

Vinícius Martim 9368553

Ariel Alejandro Arce Maciel 9294530

## Introdução
Como trabalho da disciplina de sistemas embarcados, foi desenvolvido um sistema eletrônico que permite configurar a distribuição de frenagem no veículo Baja SAE da Equipe EESC USP. O sistema de freio da equipe é composto por dois cilindros mestres (dianteiro e traseiro) e um balance bar que permite a distribuição de forças entre os cilindros, obtendo valores entre de 30% e 70% na dianteira.

O sistema eletrônico permite que o piloto configure a distribuição de frenagem entre o eixo dianteiro e traseiro de forma rápida a partir do painel do veículo, não sendo necessario apoio externo nem o uso de nenhuma ferramenta, auxiliando a equipe durante a competição. Além de facilitar a configuração o sistema é muito ultíl em casos como os a seguir: Caso haja perda de frenagem durante o enduro em um dos eixos é possivel distribuir a frenagem para o outro; Auxiliar na estrategia da equipe durante as provas dinâmicas no quesito variação de setup em parque fechado onde não é permitido trabalhar no carro entre os eventos.

## Arquitetura
O sistema é composto por um motor DC, dois potênciometros, um display 7 segmentos e o controlador (Beagle Bone Black). O motor altera a distribuição de frenagem a partir do acionamento de um fuso que movimenta linearmente o apoio do balance bar, a distribuição atual é medida a partir de um potenciômetro linear acoplado ao mesmo apoio. No painel, quando acionado, é exposto ao piloto a distribuição atual de frenagem que pode ser alterada a partir de um potenciometro angular. O sistema irá acionar o motor movendo o apoio até que a posição dos dois potenciometros seja a mesma. Para controle do motor foi utilizado uma ponte H, essa alimentada por uma fonte externa de 12V e para representação da distribuição atual foi utilizado o CI 74ls48 para conversão do sinal BCD em 7 segmentos. [Clque aqui](https://github.com/leonardosimiao/trabalho-embarcados/blob/master/Arquitetura.pdf) para visualizar um esquematico da arquitetura.

## Desenvolvimento
### Hardware
O sistema foi inicialmente prototipado utilizado uma protoboard, o motor foi ligado diretamente a um potênciometro angular com o intuito de facilitar a transmissão do torque sem a necessidade de manufaturar as engrenagens adaptadas ao motor e ao sistema de balance bar. O potênciometro de controle foi fixado ao sistema e um display simples de 7 segmentos foi utilizado para representar o painel.

### Software
Para o controle foi desenvolvido um código simples em linguagem C, esse acessa o sinal analógico dos dois potênciomentros e converte os valores para porcentagem de distribuição. Os valores são comparados, o resultado indica o sentido de rotação do motor ou se esse deve permanecer parado, e é enviado o sinal de controle para a ponte H. Para cada ciclo de execução é feita a conversão do valor do potenciometro linear (distribuição atual) para codigo BCD onde o sinal é enviado e posteriormenente convertido em 7 segmentos pelo CI. [Clique aqui](https://github.com/leonardosimiao/trabalho-embarcados/blob/master/brake_bias.c) para visulizar o código. 

## Configuração para uso da BeagleBone Black

O código [config_port_minus_adc.c](https://github.com/leonardosimiao/trabalho-embarcados/blob/master/config_port_minus_adc.c) configura as portas que devem ser utilizadas para o funcionamento do programa (necessário ter privilégio de administrador - usar *sudo*).

Caso a versão do S.O. da BeagleBone utilizada não apresente as entradas analógicas configuradas (como foi o nosso caso inicialmente) é necessária a utilização de um Device Tree Overlay. Recomenda-se seguir as orientações presentes [neste link](https://www.teachmemicro.com/beaglebone-black-adc/). Neste caso, o código [config_port.c](https://github.com/leonardosimiao/trabalho-embarcados/blob/master/config_port.c) deve ser utilizado ao invés do anterior (necessário rodar através do *root*).

O código [brake_bias.c](https://github.com/leonardosimiao/trabalho-embarcados/blob/master/brake_bias.c) é o código fonte para a realização da tarefa central do trabalho.

Na pasta [bin](https://github.com/leonardosimiao/trabalho-embarcados/tree/master/bin) estão localizados os executáveis dos códigos descritos, compilados para ARM-linux (BeagleBone Black).

O arquivo [bbb_pinout](https://github.com/leonardosimiao/trabalho-embarcados/blob/master/bbb_pinout.pdf) demonstra como deve ser feita a conexão entre a placa e o circuito.

## Vídeo Relatório
[Clique aqui](https://youtu.be/gwrGrYB9bkY) para acessar o video relatório.
