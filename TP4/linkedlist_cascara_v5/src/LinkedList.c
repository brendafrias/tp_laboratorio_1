#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if ( this != NULL )
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    if ( this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;

        for (int i = 0; i < nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && (nodeIndex>=0 && nodeIndex<=ll_len(this)))
    {
        Node* nuevoNode= (Node*)malloc(sizeof(Node));

        if(nuevoNode!=NULL)
        {
            nuevoNode->pElement= pElement;
            nuevoNode->pNextNode= NULL;

            Node* previoNode= getNode(this,nodeIndex-1);

            if(previoNode==NULL)
            {
                nuevoNode->pNextNode= this->pFirstNode;
                this->pFirstNode= nuevoNode;
            }
            else
            {
                nuevoNode->pNextNode= previoNode->pNextNode;
                previoNode->pNextNode= nuevoNode;
            }
            this->size++;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo;
    Node* prev;

    int len=ll_len(this);

    if(this != NULL)
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;
                prev=getNode(this,len-1);

                if(prev ==NULL)
                    {
                        this->pFirstNode=nuevoNodo;
                    }
                    else
                        {
                            prev->pNextNode=nuevoNodo;
                        }
                    this->size++;
                    returnAux=0;
            }
            //addNode(this,ll_len(this),pElement);


        }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index >=0 && index <= ll_len(this))
        {
            auxNode=getNode(this,index);
            if(auxNode !=NULL)
                {
                    returnAux= auxNode->pElement;
                }



        }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
 int returnAux = -1;

    if(this!=NULL && (index>=0 && index<ll_len(this)))
    {
        Node* auxNode= getNode(this,index);

        if(auxNode!=NULL)
        {
            auxNode->pElement= pElement;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
     int returnAux = -1;
     int len = ll_len(this);
     Node* auxNode;

     if(this != NULL && index >= 0 && index < len)
        {
            auxNode=getNode(this,index);// ll_get(this,index);

            if(auxNode !=NULL)
                {

                    Node* prevNode= getNode(this,index-1);

            if(prevNode==NULL)
            {
                this->pFirstNode= auxNode->pNextNode;
                free(auxNode);
            }
            else
            {
                prevNode->pNextNode= auxNode->pNextNode;
                free(auxNode);
            }
            this->size--;
            returnAux=0;

                }


        }




    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len= ll_len(this);
    Node* auxNode =NULL;


    if(this != NULL)
        {
            for(int i =len; i>0;i--)
                {
                     auxNode=getNode(this,i);// ll_get(this,index);

                        free(auxNode);
                        this->size--;



                }
            returnAux=0;

        }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
        {
            ll_clear(this);

            free(this);

            returnAux=0;
        }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;
    int len=ll_len(this);
    int j;


    if(this != NULL )
        {
            for(int i =0;i<len;i++)
                {
                    auxNode=getNode(this,i);

                    if(auxNode->pElement == pElement)
                        {
                            j=i;
                            returnAux= j;
                            break;


                        }
                }
        }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this!=NULL)
    {
        if(len>0)
        {
            returnAux=0;
        }
        else
            {
                returnAux=1;
            }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
     int returnAux = -1;

    if(this!=NULL && (index>=0 && index<=ll_len(this)))
    {
        Node* auxNode= (Node*)malloc(sizeof(Node));

        if(auxNode!=NULL)
        {
            auxNode->pElement = pElement;
            auxNode->pNextNode = NULL;

            Node* prevNode= getNode(this, index-1);

            if(prevNode==NULL)
            {
                this->pFirstNode = auxNode;
            }
            else
            {
                auxNode->pNextNode = prevNode->pNextNode;
                prevNode->pNextNode = auxNode;
            }
            this->size++;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len= ll_len(this);

        if(this != NULL && index>=0 && index<len)
            {

                returnAux=ll_get(this,index);

                ll_remove(this,index);
            }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len= ll_len(this);
    Node* auxNode;

        if(this != NULL)
            {
                auxNode= NULL;
                returnAux=0;

                for(int i=0;i<len;i++)
                    {
                        auxNode= getNode(this,i);

                        if(auxNode->pElement == pElement)
                            {

                                        returnAux=1;
                                        break;

                            }
                    }
            }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
   int returnAux = -1;

    if(this!=NULL && this2!=NULL)
    {
        Node* auxNode1= NULL;
        Node* auxNode2= NULL;

        returnAux=1;

        for(int i=0; i<ll_len(this); i++)
        {
            auxNode1= getNode(this,i);
            auxNode2= getNode(this2,i);

            if(auxNode1->pElement != auxNode2->pElement)
            {
                returnAux=0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;


    void* toLoadElement = NULL;

    if ( this != NULL && from >= 0 && to <= ll_len(this) )
    {
        cloneArray = ll_newLinkedList();

        if ( cloneArray != NULL )
        {
            for ( int i = from; i <= to; i++ )
            {
                toLoadElement = ll_get(this, i);

                if ( toLoadElement != NULL )
                {
                    ll_add(cloneArray, toLoadElement);
                }
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
   LinkedList* cloneArray = NULL;
    void* toLoadNode = NULL;

    if ( this != NULL )
    {
        cloneArray = ll_newLinkedList();

        if ( cloneArray != NULL )
        {
            for ( int i = 0; i < ll_len(this); i++)
            {
                toLoadNode = ll_get(this,i);
                if( toLoadNode != NULL)
                {
                    ll_add(cloneArray, toLoadNode);
                }
            }
        }
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
 int returnAux =-1;
    void* pAux;
    void* elemento1;
    void* elemento2;

    if( this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(int i=0; i< (ll_len(this)-1) ; i++)
        {
            for(int j= i+1; j < ll_len(this); j++)
            {
                elemento1 = ll_get(this,i);
                elemento2 = ll_get(this,j);

                if(order == 1 && pFunc(elemento1,elemento2) > 0)
                {
                    pAux = elemento1;
                    ll_set(this, i, elemento2);
                    ll_set(this, j, pAux);
                }
                else if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
                {
                    pAux = elemento1;
                    ll_set(this, i, elemento2);
                    ll_set(this, j, pAux);
                }
            }
        }

        returnAux = 0;
    }

    return returnAux;

}

// fALTA VERIFICAR PORQUE PUTAS NO ENTRA A LOS ORDER
