#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


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
    if(this != NULL){
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *  \param this LinkedList* Puntero a la lista
 *  \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        returnAux=this->size;
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
    int i;
    if(this != NULL && ll_len(this)>0 && nodeIndex >= 0 && nodeIndex < ll_len(this)){
        pNode = this->pFirstNode;
        for(i=0; i<nodeIndex; i++) {
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *  \param this LinkedList* Puntero a la lista
 *  \param index int Indice del nodo a obtener
 *  \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
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
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
        if(this->pFirstNode == NULL && nodeIndex == 0) {
            this->pFirstNode = newNode;
            this->size++;
            newNode->pElement = pElement;
            returnAux = 0;
        }
        else if(nodeIndex > 0 && nodeIndex <= ll_len(this)){
            Node* previousNode = getNode(this, nodeIndex-1);
            Node* nextNode = previousNode->pNextNode;
            previousNode->pNextNode = newNode;
            newNode->pNextNode = nextNode;
            this->size++;
            newNode->pElement = pElement;
            returnAux = 0;
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
    if(this != NULL){
        addNode(this,ll_len(this),pElement);
        returnAux=0;
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
    Node* auxNode = NULL;
    if(this != NULL && ll_len(this)>0 && index >= 0 && index < ll_len(this)){
        auxNode = getNode(this, index);
        returnAux = auxNode->pElement;
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
    Node* auxNode = NULL;
    if(this != NULL && ll_len(this)>0 && index >= 0 && index < ll_len(this)){
        auxNode = getNode(this, index);
        auxNode->pElement = pElement;
        returnAux = 0;
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
    Node* pNode=NULL;
    Node* pNodeAux=NULL;
    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this)> 0){
        if(index !=0 && index != (ll_len(this))){
            pNodeAux = getNode(this,(index-1));
            pNode = getNode(this,index);
            pNodeAux->pNextNode = pNode->pNextNode;
            free(pNode);
        }
        else if(index == 0){
            pNode = getNode(this, index);
            this->pFirstNode = pNode->pNextNode;
            free(pNode);
        }
        else if(index!=0 && index == (ll_len(this))){
            free(pNode);
        }
        this->size--;
        returnAux=0;
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
    int i;
    if(this != NULL){
        for(i=(ll_len(this)); i>=0; i--){
            ll_remove(this,i);
        }
        returnAux = 0;
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
    if(this != NULL){
        ll_clear(this);
        free(this);
        returnAux = 0;
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
    int i;
    Node* pAuxNode = NULL;
    if(this != NULL){
        for(i=0; i<ll_len(this); i++){
            pAuxNode = getNode(this, i);
            if(pAuxNode->pElement == pElement){
                returnAux = i;
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
    if(this != NULL){
        if(ll_len(this) > 0){
            returnAux = 0;
        }
        else{
            returnAux = 1;
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
    if(this != NULL && index >= 0 && index <=ll_len(this)){
        returnAux = addNode(this, index, pElement);
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
    if(this != NULL && index >= 0 && index <= ll_len(this)){
        returnAux = ll_get(this, index);
        if(returnAux != NULL){
            ll_remove(this, index);
        }
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
    int i;
    Node* pNodo = NULL;
    if(this != NULL){
        returnAux = 0;
        for(i=0; i<ll_len(this); i++){
            pNodo = getNode(this, i);
            if(pNodo->pElement == pElement){
                returnAux = 1;
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
    void* pAuxiliar = NULL;
    int retorno;
    int i;
    if(this != NULL &&  this2 != NULL){
        returnAux = 1;
        for(i=0; i<ll_len(this2); i++){
            pAuxiliar = ll_get(this, i);
            retorno = ll_contains(this2, pAuxiliar);
            if(retorno == 0){
                returnAux = 0;
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
    void* pAuxiliar = NULL;
    int i;
    if(this != NULL && from >= 0 && from<ll_len(this) && to>=0 && to<=ll_len(this)){
        cloneArray = ll_newLinkedList();
        for(i=from; i<to; i++){
            pAuxiliar = ll_get(this, i);
            ll_add(cloneArray, pAuxiliar);
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
    if(this!=NULL){
        cloneArray = ll_subList(this, 0, ll_len(this));
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
    int returnAux = -1;
    void* nodeUno = NULL;
    void* nodeDos = NULL;
    void* temp = NULL;
    int i,j;
    int flag = 0;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){
        do{
            for(i=0 ; i < (this->size-1) ; i++){
                nodeUno = ll_get(this, i);
                for(j = i+1 ; j < (this->size) ; j++){
                    nodeDos = ll_get(this, j);
                    if(order == 0){
                        if(pFunc(nodeUno, nodeDos) < 0){
                            temp = nodeDos;
                            nodeDos = nodeUno;
                            nodeUno = temp;
                        }
                    }
                    if(order == 1){
                         if(pFunc(nodeUno, nodeDos) > 0){
                            temp = nodeUno;
                            nodeUno = nodeDos;
                            nodeDos = temp;
                        }
                    }
                    ll_set(this, i, nodeUno);
                    ll_set(this, j, nodeDos);
                    flag = 1;
                }
            }
            returnAux = 0;
        }while(flag);
    }
    return returnAux;
}


/** \brief Filtra una lista dependiendo el retorno de la funcion
 *
 * \param this puntero a LinkedList
 * \param int Retorno de la funcion
 * \return LinkedList* Puntero a LinkedList
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* this2=NULL;
    void* pElement=NULL;
    int i;
    if(this != NULL && pFunc != NULL && !ll_isEmpty(this))
    {
        this2= ll_newLinkedList();
        for(i=0; i<ll_len(this); i++)
        {
            pElement=ll_get(this,i);
            if(pFunc(pElement))
            {
                ll_add(this2,pElement);
            }
        }
    }
    return this2;
}

/** \brief Leé los item de LinkedList
 *  \param this puntero a la LinkedList
 *  \param int retorno de la funcion
 *  \return -1 si hay error, 0 si salio todo ok
 */
int ll_map(LinkedList* this, void (*pFunc)(void*))
{
    int retorno = -1;
    void* pElement = NULL;
    int i;
    if(this != NULL && pFunc != NULL && !ll_isEmpty(this)){
        for(i=0; i<ll_len(this); i++){
            pElement = ll_get(this, i);
            pFunc(pElement);
            retorno = 0;
        }
    }
    return retorno;
}
