Luana Moreira de Oliveira 156315
Willian Melo Fernandes 148343

MP1 - Modelos Físicos

Para conseguir simular um comportamento oscilatório massa mola, adicionamos dois atributos à nossa classe Corpo: aceleracao e coeficienteMola. O coeficienteMola (k) é passado como parâmetro no construtor, e a aceleracao é atualizada a cada iteração, apenas para podermos exibí-la na tela.
Atualizamos o método update da classe Física para que a cada iteração, a aceleracao assuma o valor de -k*x/m. Em seguida, baseada nessa aceleração, calculamos a velocidade média, e, com essa, a posição média.