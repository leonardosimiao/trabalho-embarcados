# Sistema de distribuição de frenagem
Como trabalho da disciplina de sistemas embarcados, foi desenvolvido um sistema eletronico que permite configurar a distribuição de frenagem no veículo Baja SAE da Equipe EESC USP. O sistema de freio é composto por dois cilindros mestres e um balance bar que permite a distribuição de forças entre os cilindros.

O sistema eletrônico permite que o piloto configure a distribuição frenagem entre os eixos dianteiro e traseiro de forma rápida a partir do painel do veículo, não sendo necessario apoio externo ou de nenhuma ferramenta, auxiliando a equipe durante a competição. Exemplos de aplicação são: Caso haja perda de frenagem durante o enduro em um dos eixos é possivel distribuir a frenagem para o outro; Auxiliar na estrategia da equipe durante as provas dinamicas no quesito variação de setup em parque fechado (ninguem pode mexer no veículo entre as provas); entre outros.

## Arquitetura
O é composto por um motor DC, dois potênciometros, um display 7 segmentos e o controlador (no caso uma Beagle Bone Black, requisito da disciplina de sistemas embarcados). O motor controla a distribuição de frenagem a partir do acionamento de um fuso que movimenta linearmente o apoio do balance bar, a distribuição atual é medida a partir de um potênciometro linear acoplado ao mesmo apoio. No painel, quando acionado, é exposto ao piloto a distribuição atual de frenagem e o mesmo pode altera-la a partir de um potenciometro. O sistema irá acionar o motor movendo o apoio até que a posição dos dois potenciometros seja a mesma. [Clque aqui](https://github.com/leonardosimiao/trabalho-embarcados/blob/master/Arquitetura.pdf) para visualizar a arquitetura.

## Descrição dos arquivos
O código config_port configura as portas que devem ser utilizadas para o funcionamento do programa (necessário rodá-lo através do root).
O código config_port_minus_ADC é semelhante ao config_port, mas considera que as entradas analógicas já estão configuradas.


O código brake-bias é o código fonte para o trabalho.


Na pasta [bin](https://github.com/leonardosimiao/trabalho-embarcados/tree/master/bin) estão localizados os executáveis dos códigos descritos, compilados para ARM-linux (beaglebone black).
