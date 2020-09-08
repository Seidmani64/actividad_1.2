#include <iostream>
#include <vector>

//Metodo para intercambiar dos elementos dentro del vector
void swap(int i, int j, std::vector<int> &arr)
{
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

//Metodo de insertion sort
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

//Metodo de bubble sort
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

//Metodo de quick sort
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

//Metodo de busqueda secuencial
int busqSecuencial(std::vector<int> &arr, int n)
    {
        for(int i = 0; i<arr.size();i++)
        {
            if(arr[i] == n)
                return i;
        }
        return -1;
    }

//Metodo de busqueda binaria
int busqBinaria(std::vector<int> &arr, int n, int f, int l)
    {
        if(f >= l)
            return -1;
            
        int h = (f+l)/2;
        if(arr[h] == n)
            return h;
        if(arr[h] > n)
            return busqBinaria(arr, n, f, h-1);
        if(arr[h] < n)
            return busqBinaria(arr, n, h+1, l);
        
        return -1;
    }

//Dentro del main se genera el vector aleatoriamente
//El usuario elige el metodo de ordenamiento y se corren ambos metodos de busqueda

/*
PRUEBAS LOCALIZADAS EN UN tester.cpp POR SIMPLICIDAD
*/
int main()
{
    //Pide precondiciones del usuario y crea vector de numeros enteros
    int elementCount,findCount;
    std::cout<<"Elige la cantidad de elementos en el arreglo: "<<std::endl;
    std::cin>>elementCount;
    std::cout<<"Elige la cantidad de elementos a buscar: "<<std::endl;
    std::cin>>findCount;
    std::vector<int> arr_f;
    for (int i = 0; i < elementCount; i++)
    {
        arr_f.push_back((int)rand());
    }


    //For loop corre n veces igual a la cantidad de elementos a buscar
    //Cada loop realiza el proceso de ordenamiento que pida el usuario
    //Luego busca el numero que pida el usuario dentro del arreglo con ambos metodos
    for(int i = 0; i < findCount; i++)
    {
        //Crea una copia del vector para utilizar en esta busqueda
        //Pide precondiciones del usuario para realizar la busqueda
        std::vector<int> arr(arr_f);
        int whichOrder, numFind;
        std::cout<<"Ahora vas a elegir el metodo de sorteo. \nEscribe 1 para ordenar con insertionSort\nEscribe 2 para ordenar con bubbleSort\nEscribe 3 para ordenar con quickSort"<<std::endl;  
        std::cin>>whichOrder;
        std::cout<<"Ahora elige el numero que quieras encontrar dentro del arreglo"<<std::endl;
        std::cin>>numFind;

        //Se realiza la busqueda secuencial antes de ordenar el arreglo
        std::cout<<"El indice de tu numero (segun la busqueda secuencial) es: "<<busqSecuencial(arr, numFind)<<std::endl;

        if(whichOrder == 1)
        {
            ordenaInsercion(arr);
        }

        if(whichOrder == 2)
        {
            ordenaBurbuja(arr);
        }

        if(whichOrder == 3)
        {
            ordenaQuick(arr, 0, arr.size()-1);
        }

        std::cout<<"El indice de tu numero (segun la busqueda binaria) es: "<<busqBinaria(arr, numFind, 0, arr.size()-1)<<std::endl;

    }

}