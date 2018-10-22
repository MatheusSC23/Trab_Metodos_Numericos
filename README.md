# Trabalho 1 de Métodos Numéricos

## Equipe

 - Francisco San Diego de Sousa Castilho [@SanDiegoCastilho](https://github.com/SanDiegoCastilho)
 - Matheus Sousa Correia [@Lukiam23](https://github.com/Lukiam23)
 - Samir Braga Chaves [@samirbraga](https://github.com/samirbraga)
 - Tibet Teixeira[@tibet-teixeira](https://github.com/tibet-teixeira)
 - Franklyn Seabra [@Franklyn-S](https://github.com/Franklyn-S)
 - Daniel de Queiroz [@dqrtec](https://github.com/dqrtec)

## Especificações

O deslocamento da extremidade de um foguete espacial ao entrar na atmosfera da terra é dado pela equação f(d) = a*d – d*ln(d), onde d é
o deslocamento medido em cm e a é um parâmetro de ajuste para que se projete um foguete com a máxima segurança e eficiência
possível. Caso esse deslocamento passe dos 2 cm esse foguete irá explodir, causando sérios danos e um prejuízo gigantesco. Vários testes
e simulações são feitos de modo a garantir que o foguete seja desenvolvido com toda segurança possível. Desenvolva um sistema para
calcular esse deslocamento d da extremidade de um foguete espacial considerado com todos os requisitos apresentados nos itens abaixo:

- **Implementar algoritmo para calcular d pelo método da Bisseção.**
- **Implementar algoritmo para calcular d pelo método da Posição Falsa.**
- **Implementar algoritmo para calcular d pelo método de Newton-Raphson.**
- **Calibrar o sistema usando como padrão a = 1, isolamento = (2, 3) e \phi = 10-5.**
- **Fornecer um quadro resposta, variando os valores de a para vários foguetes.**
- **Fornecer um quadro comparativo, com isolamento, raízes e dados para cada método.**
- **Analisar o efeito da variação do valor de a de cada foguete, para cada método dado.**


## Contribuições e Divisao de tarefas

- **[@SanDiegoCastilho](https://github.com/SanDiegoCastilho) - Metodos, Slide, Lider**
- **[@Lukiam23](https://github.com/Lukiam23) - Metodos, Diagrama de Classes**
- **[@samirbraga](https://github.com/samirbraga) - Metodos, Interface Grafica**
- **[@tibet-teixeira](https://github.com/tibet-teixeira) - Metodos, Slide**
- **[@Franklyn-S](https://github.com/Franklyn-S) - Metodos, Slide**
- **[@dqrtec](https://github.com/dqrtec) - Documentação, Slide, Interface Grafica**



## Comportamento da funcao f(d)= A*d - d*ln(d)

```OBS: Para todo **A >= ln(2)** o foguete explode. Sendo 2 o deslocamento máximo```
<br>
```A=3```<br>
![a3](https://user-images.githubusercontent.com/20565933/47260569-76e88b80-d494-11e8-82ec-ae5ef52d01e4.png)
<br>
```A=1```<br>
![a1](https://user-images.githubusercontent.com/20565933/47260573-87990180-d494-11e8-9da1-7bc6af3e8eed.png)
<br>
```A=0.5```<br>
![a05](https://user-images.githubusercontent.com/20565933/47260580-941d5a00-d494-11e8-8fc1-f3822908a1a8.png)
<br>
```A=0.0000001```<br>
![a00000001](https://user-images.githubusercontent.com/20565933/47260586-a1d2df80-d494-11e8-9f31-ed8ac65a9f6e.png)
