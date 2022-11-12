#include <string>
#include <thread>

using namespace std;

/*
    Bot player2;
    thread duo(b_create, e[1], player2);
    Bot player3;
    thread tres(b_create, e[2], player3);
    Bot player4;
    thread quattuor(b_create, e[3], player4);
    Bot player5;
    thread quinque(b_create, e[4], player5);
    Bot player6;
    thread sex(b_create, e[5], player6);

    bool win_con = false;
    do
    {
        


    } while (win_con==false);

    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    quinque.join();
    sex.join();
    return 0;
}
*/


int Mone(){
    cout<<"Mone : MXXXXX"<<endl;
    return 1;
}
int Mtwo(){
    cout<<"Mtwo : MAXXXX"<<endl;
    return 1;
}
int Mthr(){
    cout<<"Mthr : MAAXXX"<<endl;
    return 1;
}
int Mfou(){
    cout<<"Mfou : MAAAXX"<<endl;
    return 1;
}
int Mfiv(){
    cout<<"Mfiv : MAAAAX"<<endl;
    return 1;
}
int Msix(){
    cout<<"Msix : MAAAAA"<<endl;
    return 1;
}

int Aone(){
    cout<<"Aone : AXXXXX"<<endl;
    return 1;
}
int Atwo(){
    cout<<"Atwo : AAXXXX"<<endl;
    return 1;
}
int Athr(){
    cout<<"Athr : AAAXXX"<<endl;
    return 1;
}
int Afou(){
    cout<<"Afou : AAAAXX"<<endl;
    return 1;
}
int Afiv(){
    cout<<"Afiv : AAAAAX"<<endl;
    return 1;
}
int Asix(){
    cout<<"Asix : AAAAAA"<<endl;
    return 1;
}


int PlayerController(string e[5]){

    const string X = "X";
    const string M = "M";
    int i=0;
    bool end=false;

    do{
        if((e[i]=="X")||(i==6))
            end=true;
        else
            i++;
    }while(end==false);

    if(e[0]==M){
        switch (i)
        {
        case 1 :
            Mone();
            break;
        case 2 :
            Mtwo();
            break;
        case 3 :
            Mthr();
            break;
        case 4 :
            Mfou();
            break;
        case 5 :
            Mfiv();
            break;  
        default:
            Msix();
            break;
        }
    }
    else{
        switch (i)
        {
        case 1 :
            Aone();
            break;
        case 2 :
            Atwo();
            break;
        case 3 :
            Athr();
            break;
        case 4 :
            Afou();
            break;
        case 5 :
            Afiv();
            break;  
        default:
            Asix();
            break;
        }
    }


    /*
    
    thread unus(execute, player1);
    thread duo(execute, player2);
    thread tres(execute, player3);
    thread quattuor(execute, player4);
    thread quinque(execute, player5);
    thread sex(execute, player6);


    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    quinque.join();
    sex.join();
    */
    return 0;
}

