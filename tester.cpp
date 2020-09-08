#include <iostream>
#include <vector>


void swap(int i, int j, std::vector<int> &arr)
{
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}


void ordenaInsercion(std::vector<int> &arr)
{
    int key;
        for (size_t i = 1; i < arr.size(); i++)
        {
            key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }      
}


void ordenaBurbuja(std::vector<int> &arr)
{
    bool noSwap = true;
    for(size_t i = 0; i < arr.size(); i++)
        {
            noSwap = true;
            for(size_t j = 0; j < arr.size()- i-1; j++)
                if(arr[j] > arr[j+1])
                {
                    swap(j+1,j,arr);
                    noSwap = false;
                }
            if(noSwap == true)
                break;
        }    
}


void ordenaQuick(std::vector<int> &arr, int low, int high)
{
        if(low < high)
        {
            int pivot = arr[high];
            int i = low - 1;
            for (size_t j = low; j <= high-1; j++)
            {
                if(arr[j] < pivot)
                {
                    i++;
                    swap(i, j, arr);
                }
            }
            swap(i+1, high, arr);
            int piv = (i+1);

            ordenaQuick(arr, low, piv - 1);
            ordenaQuick(arr, piv + 1, high);
        }  
}


int busqSecuencial(std::vector<int> &arr, int n)
    {
        for(int i = 0; i<arr.size();i++)
        {
            if(arr[i] == n)
                return i;
        }
        return -1;
    }


int busqBinaria(std::vector<int> &arr, int n, int f, int l)
    {
        if(f >= l)
            return -1;
            
        int h = (f+l)/2;
        if(arr[h] == n)
            return h;
        else if(arr[h] > n)
            return busqBinaria(arr, n, f, h-1);
        else if(arr[h] < n)
            return busqBinaria(arr, n, h+1, l);
        
        return -1;
    }



int main()
{
    //Generacion de arreglo sencillo de 1 a 10 para casos prueba
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(10);
    arr.push_back(9);
    arr.push_back(6);
    arr.push_back(8);

    //Generacion de tres copias del arreglo para probar cada metodo de sorteo
    std::vector<int> arr_b(arr);
    std::vector<int> arr_i(arr);
    std::vector<int> arr_q(arr);
    ordenaBurbuja(arr_b);
    ordenaInsercion(arr_i);
    ordenaQuick(arr_q, 0, arr_q.size()-1);

    //Prueba para ver que los vectores ordenados sean iguales
    if(arr_b==arr_i && arr_b==arr_q)
        std::cout<<"Los arreglos ordenados son iguales."<<std::endl;
    else std::cout<<"Los arreglos ordenados no son iguales."<<std::endl;

    //Cuatro pruebas de busqueda secuencial utilizando el arreglo no ordenado
    std::cout<<"\nPrueba 1 busqueda secuencial\nIndice esperado de numero 3 es: 4\nIndice resultado es: "<<busqSecuencial(arr, 3)<<std::endl;
    std::cout<<"\nPrueba 2 busqueda secuencial\nIndice esperado de numero 1 es: 0\nIndice resultado es: "<<busqSecuencial(arr, 0)<<std::endl;
    std::cout<<"\nPrueba 3 busqueda secuencial\nIndice esperado de numero 15 es: -1\nIndice resultado es: "<<busqSecuencial(arr, 15)<<std::endl;
    std::cout<<"\nPrueba 4 busqueda secuencial\nIndice esperado de numero 8 es: 9\nIndice resultado es: "<<busqSecuencial(arr, 8)<<std::endl;

    //Cuatro pruebas de busqueda binaria utilizando uno de los arreglos ordenados
    std::cout<<"\nPrueba 1 busqueda binaria\nIndice esperado de numero 3 es: 2\nIndice resultado es: "<<busqBinaria(arr_b, 3, 0, arr_b.size()-1)<<std::endl;
    std::cout<<"\nPrueba 2 busqueda binaria\nIndice esperado de numero 1 es: 0\nIndice resultado es: "<<busqBinaria(arr_b, 1, 0, arr_b.size()-1)<<std::endl;
    std::cout<<"\nPrueba 3 busqueda binaria\nIndice esperado de numero 15 es: -1\nIndice resultado es: "<<busqBinaria(arr_b, 15, 0, arr_b.size()-1)<<std::endl;
    std::cout<<"\nPrueba 4 busqueda binaria\nIndice esperado de numero 8 es: 7\nIndice resultado es: "<<busqBinaria(arr_b, 8, 0, arr_b.size()-1)<<std::endl;

}