# Trabalho 1 de Métodos Numéricos

## Equipe

- **[@SanDiegoCastilho](https://github.com/SanDiegoCastilho) - Métodos, Slide, Lider**
- **[@Lukiam23](https://github.com/Lukiam23) - Métodos, Diagrama de Classes**
- **[@samirbraga](https://github.com/samirbraga) - Métodos**
- **[@tibet-teixeira](https://github.com/tibet-teixeira) - Métodos, Slide**
- **[@Franklyn-S](https://github.com/Franklyn-S) - Métodos**
- **[@dqrtec](https://github.com/dqrtec) - Documentação, Slide, Interface Grafica**

## Especificações

O deslocamento da extremidade de um foguete espacial ao entrar na atmosfera da terra é dado pela equação f(d) = a * d – d* ln(d), onde d é o deslocamento medido em cm e a é um parâmetro de ajuste para que se projete um foguete com a máxima segurança e eficiência possível. Caso esse deslocamento passe dos 2 cm esse foguete irá explodir, causando sérios danos e um prejuízo gigantesco. Vários testes e simulações são feitos de modo a garantir que o foguete seja desenvolvido com toda segurança possível. Desenvolva um sistema para calcular esse deslocamento d da extremidade de um foguete espacial considerado com todos os requisitos apresentados nos itens abaixo:

- **Implementar algoritmo para calcular d pelo método da Bisseção.**
- **Implementar algoritmo para calcular d pelo método da Posição Falsa.**
- **Implementar algoritmo para calcular d pelo método de Newton-Raphson.**
- **Calibrar o sistema usando como padrão a = 1, isolamento = (2, 3) e &epsilon; = 10<sup>-5</sup>.**
- **Fornecer um quadro resposta, variando os valores de a para vários foguetes.**
- **Fornecer um quadro comparativo, com isolamento, raízes e dados para cada método.**
- **Analisar o efeito da variação do valor de a de cada foguete, para cada método dado.**

**Dados de entrada:** n (número de foguetes), a (de cada foguete) e &epsilon; (precisão).

**Dados de saída:** quadros resposta (com d, E<sub>A</sub> para cada foguete e método) e comparativo.


## Comportamento da funcao f(d)= A*d - d*ln(d)

![a00000001](https://user-images.githubusercontent.com/20565933/47260586-a1d2df80-d494-11e8-9f31-ed8ac65a9f6e.png)

