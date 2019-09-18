# include <bits/stdc++.h>
using namespace std;

string automata (vector<vector<int>> &Tabla, string cad, map<char, string> &mapTokens, map<string, int> &mapIndx)
{
    int estado=1;
    int entrada;
    for (auto simbolo:cad){
        if (!mapTokens.count(simbolo)){
            return "error";
        }
        entrada = mapIndx[mapTokens[simbolo]];
        estado = Tabla[estado][entrada];
        if (estado==-1){
            return "error";
        }
    }
    
    if (!Tabla[estado][mapTokens.size()+1]){
        return "ok";
    }
    return "error";
} 

int main ()
{
    freopen("tablas.in", "r", stdin);
        
    int cantTablas, cantTokens, cantEstados, celdas, cantCadenas, estado;
    string token, simbolos, cad;

    cin>>cantTablas;

    for (int i=0; i<cantTablas; i++){
    
        map<char, string> mapTokens;
        map<string, int> mapIndx;
        cin>>cantTokens;
        for (int j=0; j<cantTokens; j++){
            cin>>token;
            cin>>simbolos;
            for (auto s:simbolos){
                mapTokens.insert({s,token});
            }
            mapIndx.insert({token,j+1});
        }
        
        cin>>cantEstados;
        celdas = cantEstados*(cantTokens+1);//+1 para fin de caracteres
        vector<vector<int>> Tabla(cantEstados+1);//para índices desde 1
        for(int j=1; j<=cantEstados; j++){
            Tabla[j].push_back(-1);
        }
        for (int j=0; j<celdas; j++){
            cin>>estado;
            Tabla[j/(cantTokens+1)+1].push_back(estado);
        }
        
        cin>>cantCadenas;
        for (int j=0; j<cantCadenas; j++){
            cin>>cad;
            cout<<cad<<" "<<automata (Tabla, cad, mapTokens, mapIndx)<<"\n";
        }
        cout<<"\n";
    }
    
    fclose (stdin);     

    return 0;
}
