# Sistema de distribuição de frenagem
## Introdução
Como trabalho da disciplina de sistemas embarcados, foi desenvolvido um sistema eletrônico que permite configurar a distribuição de frenagem no veículo Baja SAE da Equipe EESC USP. O sistema de freio da equipe é composto por dois cilindros mestres (dianteiro e traseiro) e um balance bar que permite a distribuição de forças entre os cilindros.

O sistema eletrônico permite que o piloto configure a distribuição frenagem entre o eixo dianteiro e traseiro de forma rápida a partir do painel do veículo, não sendo necessario apoio externo ou de nenhuma ferramenta, auxiliando a equipe durante a competição. Exemplos de aplicação são: Caso haja perda de frenagem durante o enduro em um dos eixos é possivel distribuir a frenagem para o outro; Auxiliar na estrategia da equipe durante as provas dinamicas no quesito variação de setup em parque fechado (ninguem pode mexer no veículo entre as provas) dentre outros.

Para maiores informação assista ao [video-relatorio](link).

## Arquitetura
O sistema é composto por um motor DC, dois potênciometros, um display 7 segmentos e o controlador (Beagle Bone Black). O motor controla a distribuição de frenagem a partir do acionamento de um fuso que movimenta linearmente o apoio do balance bar, a distribuição atual é medida a partir de um potênciometro linear acoplado ao mesmo apoio. No painel, quando acionado, é exposto ao piloto a distribuição atual de frenagem e o mesmo pode altera-la a partir de um potenciometro. O sistema irá acionar o motor movendo o apoio até que a posição dos dois potenciometros seja a mesma. Para controle do motor foi utilizado uma ponte H, essa alimentada por uma fonte externa de 12V e para representação da distribuição atual foi utilizado o CI 74ls48 para conversão do sinal BCD em 7 segmentos. [Clque aqui](https://github.com/leonardosimiao/trabalho-embarcados/blob/master/Arquitetura.pdf) para visualizar um esquematico da arquitetura.

## Desenvolvimento
### Hardware
O sistema foi inicialmente prototipado utilizado uma protoboard, demonstrada no video-relatório, o motor foi ligado diretamente a um potênciometro angular ao invés de um linear com o intuito de facilitar a transmissão do torque sem a necessidade de manufaturar as engrenagens adaptadas ao motor e ao sistema de balance bar. O potenciometro de controle foi fixado ao sistema e um display simples de 7 segmentos foi utilizado para representar o painel.

### Software
Para o controle foi desenvolvido um código simples na linguagem C, esse acessa o sinal analogico dos dois potênciomentros e converte os valores para porcentagem de distribuição que varia de 30 a 70. Os valores são comparados, caso o angular seja maior que linear é enviado o sinal digital ao motor para rotacionar em um sentido, caso contrario o sinal é invertido e caso sejam iguais o motor fica parado. Para cada ciclo de execução é feita a conversão do valor do potenciometro linear para codigo BCD onde o sinal é enviado e posteriormenente convertido em 7 segmentos pelo CI. [Clique aqui](https://github.com/leonardosimiao/trabalho-embarcados/blob/master/brake-bias.cpp) para visulizar o código. 

## Descrição dos arquivos
O código config_port configura as portas que devem ser utilizadas para o funcionamento do programa (necessário rodá-lo através do root).
O código config_port_minus_ADC é semelhante ao config_port, mas considera que as entradas analógicas já estão configuradas.


O código brake-bias é o código fonte para o trabalho.


Na pasta [bin](https://github.com/leonardosimiao/trabalho-embarcados/tree/master/bin) estão localizados os executáveis dos códigos descritos, compilados para ARM-linux (beaglebone black).
