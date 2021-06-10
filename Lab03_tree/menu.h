#include "tests.h"


using namespace std;

template <class T>
void printBinarySearchTree(TreeElement<T>* root, int space = 0) {
    if (!root)
        return;
    enum { COUNT = 2 };
    space += COUNT;
    printBinarySearchTree(root->rightChild, space);
    for (int i = COUNT; i < space; ++i)
        std::cout << "  ";
    cout << root->data << endl;
    printBinarySearchTree(root->leftChild, space);
}


int GetInt() {
    int a;
    cin >> a;
    if (a < 1) {
        cout << "Number is out of range. Try again:";
        GetInt();
    }
    return a;
}

int GetInt(int lower, int upper) {
    int a;
    cout << "Input number: ";
    cin >> a;
    if (a > upper || a < lower) {
        cout << "Number is out of range, try again" << endl;
        GetInt(lower, upper);
    }
    return a;
}

int getNumber(int a) {
    int b;
    cin >> b;
    return b;
}

float getNumber(float a) {
    float b;
    cin >> b;
    return b;
}

int randomInt() {
    return rand() % 1000;
}

float randomFloat() {
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 100));
}

template <class T>
BinaryHeap<T>* creatBinaryHeapNotRandom() {
    cout << "Input first number: " << endl;
    T* a = new T[1];
    cin >> a[0];
    BinaryHeap<T>* binaryHeap = new BinaryHeap<T>(a, 1);
    T b;
    while (1) {
        cout << "Do you want to add number?." << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        int point = GetInt(1, 2);
        if (point == 2)
            break;
        cout << "Input number: " << endl;
        cin >> b;
        binaryHeap->AddElement(b);
    }
    for (int i = binaryHeap->GetHeapSize() / 2; i >= 0; i--)
        binaryHeap->heapify(i);
    return binaryHeap;
}

template<class T>
BinaryHeap<T>* creatBinaryHeapRandom(T func()) {
    cout << "How many numbers do you want?" << endl;
    int point = GetInt();
    T* a = new T[1];
    a[0] = func();
    BinaryHeap<T>* binaryHeap = new BinaryHeap<T>(a, 1);
    T b;
    for (int i = 0; i < point - 1; ++i) {
        b = func();
        binaryHeap->AddElement(b);
    }
    for (int i = binaryHeap->GetHeapSize() / 2; i >= 0; i--)
        binaryHeap->heapify(i);
    return binaryHeap;
}

template <class T>
void creatBinaryHeap(ArraySequence<BinaryHeap<T>*>* arraySequence, T func()) {
    cout << "Do you want to fill binary heap yourself?" << endl;
    cout << "1. Yes." << endl;
    cout << "2. No." << endl;
    int point = GetInt(1, 2);
    BinaryHeap<T>* binaryHeap = nullptr;
    switch (point) {
    case 1:
        binaryHeap = creatBinaryHeapNotRandom<T>();
        break;
    case 2:
        binaryHeap = creatBinaryHeapRandom(func);
        break;
    default: break;
    }
    arraySequence->Append(binaryHeap);
}

void chooseBinaryHeapType(ArraySequence<BinaryHeap<int>*>* binaryHeapIntArray, ArraySequence<BinaryHeap<float>*>* binaryHeapFloatArray) {
    cout << "What type  do you want?" << endl;
    cout << "1. Int." << endl;
    cout << "2. Float." << endl;
    int b = GetInt(1, 2);
    switch (b) {
    case 1:
        creatBinaryHeap(binaryHeapIntArray, randomInt);
        break;
    case 2:
        creatBinaryHeap(binaryHeapFloatArray, randomFloat);
        break;
    default: break;
    }
}

template <class T>
BinarySearchTree<T>* creatBinaryTreeRandom(T func()) {
    cout << "How many numbers do you want?" << endl;
    int point = GetInt();
    T a = func();
    BinarySearchTree<T>* binarySearchTree = new BinarySearchTree<T>(a);
    T b;
    for (int i = 0; i < point - 1; ++i) {
        b = func();
        binarySearchTree->Add(b);
    }
    return binarySearchTree;
}

template <class T>
BinarySearchTree<T>* creatBinaryTreeNotRandom() {
    cout << "Input 1 number: " << endl;
    T* a = new T[1];
    cin >> a[0];
    BinarySearchTree<T>* binarySearchTree = new BinarySearchTree<T>(a[0]);
    T b;
    while (1) {
        cout << "Do you want to add number?." << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        int point = GetInt(1, 2);
        if (point == 2)
            break;
        cout << "Input number: " << endl;
        cin >> b;
        binarySearchTree->Add(b);
    }
    return binarySearchTree;
}

template <class T>
void creatBinaryTree(ArraySequence<BinarySearchTree<T>*>* arraySequence, T func()) {
    cout << "Do you want to fill binary search tree yourself?" << endl;
    cout << "1. Yes." << endl;
    cout << "2. No." << endl;
    int point = GetInt(1, 2);
    BinarySearchTree<T>* binarySearchTree = nullptr;
    switch (point) {
    case 1:
        binarySearchTree = creatBinaryTreeNotRandom<T>();
        break;
    case 2:
        binarySearchTree = creatBinaryTreeRandom<T>(func);
        break;
    default: break;
    }
    arraySequence->Append(binarySearchTree);
}

void chooseBinarySearchTreeType(ArraySequence<BinarySearchTree<float>*>* binarySearchFloatArray, ArraySequence<BinarySearchTree<int>*>* binarySearchIntArray) {
    cout << "What type do you want?" << endl;
    cout << "1. Int." << endl;
    cout << "2. Float." << endl;
    int b = GetInt(1, 2);
    switch (b) {
    case 1:
        creatBinaryTree(binarySearchIntArray, randomInt);
        break;
    case 2:
        creatBinaryTree(binarySearchFloatArray, randomFloat);
        break;
    default:
        break;
    }
}

template <class T>
void printBinaryHeapFromMemory(ArraySequence<BinaryHeap<T>*>* arraySequence) {
    for (int i = 0; i < arraySequence->GetLength(); ++i) {
        cout << "Heap N" << i + 1 << ":";
        cout << *arraySequence->Get(i);
    }
}

void showAvailableBinaryHeaps(ArraySequence<BinaryHeap<int>*>* binaryHeapIntArray, ArraySequence<BinaryHeap<float>*>* binaryHeapFloatArray) {
    cout << "What type do you want?" << endl;
    cout << "1. Int." << endl;
    cout << "2. Float." << endl;
    int b = GetInt(1, 2);
    switch (b) {
    case 1:
        printBinaryHeapFromMemory(binaryHeapIntArray);
        break;
    case 2:
        printBinaryHeapFromMemory(binaryHeapFloatArray);
        break;
    default:
        break;
    }
}

template <class T>
void printBinaryTreesFromMemory(ArraySequence<BinarySearchTree<T>*>* arraySequence) {
    for (int i = 0; i < arraySequence->GetLength(); ++i) {
        printBinarySearchTree(arraySequence->Get(i)->GetRoot());
    }
    cout << endl << endl;
}

void showAvailableBinaryTrees(ArraySequence<BinarySearchTree<float>*>* binarySearchFloatArray, ArraySequence<BinarySearchTree<int>*>* binarySearchIntArray) {
    cout << "What type do you want?" << endl;
    cout << "1. Int." << endl;
    cout << "2. Float." << endl;
    int b = GetInt(1, 2);
    switch (b) {
    case 1:
        printBinaryTreesFromMemory(binarySearchIntArray);
        break;
    case 2:
        printBinaryTreesFromMemory(binarySearchFloatArray);
        break;
    default:
        break;
    }
}

template <class T>
BinaryHeap<T>* getBinaryHeapFromMemory(ArraySequence<BinaryHeap<T>*>* arraySequence) {
    if (arraySequence->GetLength() == 0) {
        cout << "There is no available binary heaps" << endl;
        return nullptr;
    }
    printBinaryHeapFromMemory(arraySequence);
    cout << "Which one heap do you want to use?" << endl;
    int point = GetInt(1, arraySequence->GetLength());
    auto* binaryHeap = arraySequence->Get(point - 1);
    return binaryHeap;
}

template <class T>
void AddElementBinaryHeap(ArraySequence<BinaryHeap<T>*>* arraySequence) {
    BinaryHeap<T>* binaryHeap = getBinaryHeapFromMemory(arraySequence);
    cout << "Number you want to add is?" << endl;
    T point;
    cin >> point;
    binaryHeap->AddElement(point);
}

template <class T>
void DeleteElementBinaryHeap(ArraySequence<BinaryHeap<T>*>* arraySequence) {
    BinaryHeap<T>* binaryHeap = getBinaryHeapFromMemory(arraySequence);
    cout << "Number you want to delete is?" << endl;
    T point;
    cin >> point;
    int heapSize = binaryHeap->GetHeapSize();
    binaryHeap->deleteElement(point);
    if (heapSize == binaryHeap->GetHeapSize()) {
        cout << "There is no such element as " << point << "." << endl;
        cout << "Do you want to try again?" << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        int point = GetInt(1, 2);
        switch (point) {
        case 1:
            DeleteElementBinaryHeap(arraySequence);
            break;
        case 2:
            return;
            break;
        }
    }
    cout << *binaryHeap;
}

template <class T>
void FindElementBinaryHeap(ArraySequence<BinaryHeap<T>*>* arraySequence) {
    BinaryHeap<T>* binaryHeap = getBinaryHeapFromMemory(arraySequence);
    cout << "Number you want to find is?" << endl;
    T point;
    cin >> point;
    int heapSize = binaryHeap->findElement(point);
    if (heapSize == -1) {
        cout << "There is no such element as " << point << "." << endl;
        cout << "Do you want to try again?" << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        int point = GetInt(1, 2);
        switch (point) {
        case 1:
            FindElementBinaryHeap(arraySequence);
            break;
        case 2:
            return;
            break;
        }
    }
    cout << "Your element is located on " << heapSize + 1 << " position." << endl;
}

template <class T>
T mult(T a, T b) {
    return a * b;
}

template <class T>
T add(T a, T b) {
    return a + b;
}

template <class T>
T sub(T a, T b) {
    return a - b;
}

template <class T>
T div(T a, T b) {
    return a / b;
}

template <class T>
void MapBinaryHeap(ArraySequence<BinaryHeap<T>*>* arraySequence) {
    BinaryHeap<T>* binaryHeap = getBinaryHeapFromMemory(arraySequence);
    cout << "What do you want to do?" << endl;
    cout << "1. Multiply." << endl;
    cout << "2. Divide." << endl;
    cout << "3. Add." << endl;
    cout << "4. Subtraction." << endl;
    int point = GetInt(1, 4);
    cout << "Input second operating number: ";
    int a;
    cin >> a;
    cout << endl;
    BinaryHeap<T>* binaryHeap1 = nullptr;
    switch (point) {
    case 1:
        binaryHeap1 = binaryHeap->map(mult, a);
        break;
    case 2:
        if (a == 0) {
            cout << "You cannot divide on 0" << endl;
            return;
        }
        binaryHeap1 = binaryHeap->map(div, a);
        break;
    case 3:
        binaryHeap1 = binaryHeap->map(add, a);
        break;
    case 4:
        binaryHeap1 = binaryHeap->map(sub, a);
        break;
    default: break;
    }
    cout << *binaryHeap1;
}

template <class T>
bool IsDivisibility(T a, T b) {
    if (a / b == 0)
        return true;
    return false;
}

template <class T>
bool IsMore(T a, T b) {
    if (a > b)
        return true;
    return false;
}

template <class T>
bool IsLess(T a, T b) {
    if (a < b)
        return true;
    return false;
}

template <class T>
void WhereBinaryHeap(ArraySequence<BinaryHeap<T>*>* arraySequence) {
    BinaryHeap<T>* binaryHeap = getBinaryHeapFromMemory(arraySequence);
    cout << "What do you want to do?" << endl;
    cout << "1. Divisibility." << endl;
    cout << "2. More." << endl;
    cout << "3. Less." << endl;
    int point = GetInt(1, 3);
    cout << "Input second operating number: ";
    int a;
    cin >> a;
    cout << endl;
    BinaryHeap<T>* binaryHeap1 = nullptr;
    switch (point) {
    case 1:
        binaryHeap1 = binaryHeap->where(IsDivisibility, a);
        break;
    case 2:
        binaryHeap1 = binaryHeap->where(IsMore, a);
        break;
    case 3:
        binaryHeap1 = binaryHeap->where(IsLess, a);
        break;
    default: break;
    }
    cout << *binaryHeap1;
}

template <class T>
void AllocateSubtreeBinaryHeap(ArraySequence<BinaryHeap<T>*>* arraySequence) {
    BinaryHeap<T>* binaryHeap = getBinaryHeapFromMemory(arraySequence);
    cout << "Number you want to allocate tree?" << endl;
    T point;
    cin >> point;
    int heapSize = binaryHeap->findElement(point);
    if (heapSize == -1) {
        cout << "There is no such element as " << point << "." << endl;
        cout << "Do you want to try again?" << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        int point = GetInt(1, 2);
        switch (point) {
        case 1:
            FindElementBinaryHeap(arraySequence);
            break;
        case 2:
            return;
            break;
        }
    }
    BinaryHeap<T>* binaryHeap1 = binaryHeap->subBinaryHeap(point);
    cout << *binaryHeap1;
}

void operateWithBinaryHeaps(ArraySequence<BinaryHeap<int>*>* binaryHeapIntArray, ArraySequence<BinaryHeap<float>*>* binaryHeapFloatArray) {
    cout << "What do you want to do?" << endl;
    cout << "1. Add element." << endl;
    cout << "2. Delete element." << endl;
    cout << "3. Find element." << endl;
    cout << "4. Map binary heap." << endl;
    cout << "5. Do where binary heap." << endl;
    cout << "6. Allocate subtree." << endl;
    cout << "7. Exit." << endl;
    int point = GetInt(1, 7);
    cout << "What type do you want?" << endl;
    cout << "1. Int." << endl;
    cout << "2. Float." << endl;
    int b = GetInt(1, 2);
    switch (point) {
    case 1:
        if (b == 1) {
            AddElementBinaryHeap(binaryHeapIntArray);
            break;
        }
        AddElementBinaryHeap(binaryHeapFloatArray);
        break;
    case 2:
        if (b == 1) {
            DeleteElementBinaryHeap(binaryHeapIntArray);
            break;
        }
        DeleteElementBinaryHeap(binaryHeapFloatArray);
        break;
    case 3:
        if (b == 1) {
            FindElementBinaryHeap(binaryHeapIntArray);
            break;
        }
        FindElementBinaryHeap(binaryHeapFloatArray);
        break;
    case 4:
        if (b == 1) {
            MapBinaryHeap(binaryHeapIntArray);
            break;
        }
        MapBinaryHeap(binaryHeapFloatArray);
        break;
    case 5:
        if (b == 1) {
            WhereBinaryHeap(binaryHeapIntArray);
            break;
        }
        WhereBinaryHeap(binaryHeapFloatArray);
        break;
    case 6:
        if (b == 1) {
            AllocateSubtreeBinaryHeap(binaryHeapIntArray);
            break;
        }
        AllocateSubtreeBinaryHeap(binaryHeapFloatArray);
        break;
    case 7:
        break;
    default: break;
    }
}

template<class T>
BinarySearchTree<T>* getBinaryTreeFromMemory(ArraySequence<BinarySearchTree<T>*>* arraySequence) {
    if (arraySequence->GetLength() == 0) {
        cout << "There is no available binary heaps" << endl;
        return nullptr;
    }
    printBinaryTreesFromMemory(arraySequence);
    cout << "Which one tree do you want to use?" << endl;
    int point = GetInt(1, arraySequence->GetLength());
    TreeElement<T>* newNode = arraySequence->Get(point - 1)->copyElements(arraySequence->Get(point - 1)->GetRoot());
    auto* binaryTree = new BinarySearchTree<T>(newNode);
    return binaryTree;
}

template<class T>
void AddElementBinaryTree(ArraySequence<BinarySearchTree<T>*>* arraySequence) {
    BinarySearchTree<T>* binaryTree = getBinaryTreeFromMemory(arraySequence);
    cout << "Number you want to add is?" << endl;
    T point;
    cin >> point;
    binaryTree->Add(point);
    printBinarySearchTree(binaryTree->GetRoot());
}

template <class T>
void DeleteElementBinaryTree(ArraySequence<BinarySearchTree<T>*>* arraySequence) {
    BinarySearchTree<T>* binaryTree = getBinaryTreeFromMemory(arraySequence);
    cout << "Number you want to delete is?" << endl;
    T point;
    cin >> point;
    size_t heapSize = binaryTree->GetSize();
    binaryTree->DeleteElement(point);
    if (heapSize == binaryTree->GetSize()) {
        cout << "There is no such element as " << point << "." << endl;
        cout << "Do you want to try again?" << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        int point = GetInt(1, 2);
        switch (point) {
        case 1:
            DeleteElementBinaryTree(arraySequence);
            break;
        case 2:
            return;
            break;
        }
    }
    printBinarySearchTree(binaryTree->GetRoot());
}

template <class T>
void FindElementBinaryTree(ArraySequence<BinarySearchTree<T>*>* arraySequence) {
    BinarySearchTree<T>* binaryTree = getBinaryTreeFromMemory(arraySequence);
    cout << "Number you want to find is?" << endl;
    T point;
    cin >> point;
    bool a = binaryTree->Find(point);
    if (!a) {
        cout << "There is no such element as " << point << "." << endl;
        cout << "Do you want to try again?" << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        int point = GetInt(1, 2);
        switch (point) {
        case 1:
            FindElementBinaryTree(arraySequence);
            break;
        case 2:
            return;
            break;
        }
    }
    cout << "This element " << point << " is in the tree." << endl;
}

template <class T>
void MapBinaryTree(ArraySequence<BinarySearchTree<T>*>* arraySequence) {
    BinarySearchTree<T>* binaryTree = getBinaryTreeFromMemory(arraySequence);
    cout << "What do you want to do?" << endl;
    cout << "1. Multiply." << endl;
    cout << "2. Divide." << endl;
    cout << "3. Add." << endl;
    cout << "4. Subtraction." << endl;
    int point = GetInt(1, 4);
    cout << "Input second operating number: ";
    int a;
    cin >> a;
    cout << endl;
    BinarySearchTree<T>* binarySearchTree = nullptr;
    switch (point) {
    case 1:
        binarySearchTree = binaryTree->map(mult, a);
        break;
    case 2:
        if (a == 0) {
            cout << "You cannot divide on 0" << endl;
            return;
        }
        binarySearchTree = binaryTree->map(div, a);
        break;
    case 3:
        binarySearchTree = binaryTree->map(add, a);
        break;
    case 4:
        binarySearchTree = binaryTree->map(sub, a);
        break;
    default: break;
    }
    printBinarySearchTree(binarySearchTree->GetRoot());
}

template <class T>
void WhereBinaryTree(ArraySequence<BinarySearchTree<T>*>* arraySequence) {
    BinarySearchTree<T>* binaryTree = getBinaryTreeFromMemory(arraySequence);
    cout << "What do you want to do?" << endl;
    cout << "1. Divisibility." << endl;
    cout << "2. More." << endl;
    cout << "3. Less." << endl;
    int point = GetInt(1, 3);
    cout << "Input second operating number: ";
    int a;
    cin >> a;
    cout << endl;
    BinarySearchTree<T>* binarySearchTree = nullptr;
    switch (point) {
    case 1:
        binarySearchTree = binaryTree->where(IsDivisibility, a);
        break;
    case 2:
        binarySearchTree = binaryTree->where(IsMore, a);
        break;
    case 3:
        binarySearchTree = binaryTree->where(IsLess, a);
        break;
    default: break;
    }
    printBinarySearchTree(binarySearchTree->GetRoot());
}

void operateWithBinarySearchTree(ArraySequence<BinarySearchTree<float>*>* binarySearchFloatArray, ArraySequence<BinarySearchTree<int>*>* binarySearchIntArray) {
    cout << "What do you want to do?" << endl;
    cout << "1. Add element." << endl;
    cout << "2. Delete element." << endl;
    cout << "3. Find element." << endl;
    cout << "4. Map binary search tree." << endl;
    cout << "5. Do where binary search tree." << endl;
    cout << "6. Exit." << endl;
    int point = GetInt(1, 6);
    cout << "What type do you want?" << endl;
    cout << "1. Int." << endl;
    cout << "2. Float." << endl;
    int b = GetInt(1, 2);
    switch (point) {
    case 1:
        if (b == 1) {
            AddElementBinaryTree(binarySearchIntArray);
            break;
        }
        AddElementBinaryTree(binarySearchFloatArray);
        break;
    case 2:
        if (b == 1) {
            DeleteElementBinaryTree(binarySearchIntArray);
            break;
        }
        DeleteElementBinaryTree(binarySearchFloatArray);
        break;
    case 3:
        if (b == 1) {
            FindElementBinaryTree(binarySearchIntArray);
            break;
        }
        FindElementBinaryTree(binarySearchFloatArray);
        break;
    case 4:
        if (b == 1) {
            MapBinaryTree(binarySearchIntArray);
            break;
        }
        MapBinaryTree(binarySearchFloatArray);
        break;
    case 5:
        if (b == 1) {
            WhereBinaryTree(binarySearchIntArray);
            break;
        }
        WhereBinaryTree(binarySearchFloatArray);
        break;
    case 6:
        break;
    default: break;
    }
}

void mainMenu() {
    ArraySequence<BinaryHeap<int>*> binaryHeapIntArray;
    ArraySequence<BinaryHeap<float>*> binaryHeapFloatArray;
    ArraySequence<BinarySearchTree<float>*> binarySearchFloatArray;
    ArraySequence<BinarySearchTree<int>*> binarySearchIntArray;
    while (1) {
        cout << "Menu: " << endl;
        cout << "1. Create binary heap." << endl;
        cout << "2. Create binary search tree." << endl;
        cout << "3. Show available binary heaps." << endl;
        cout << "4. Show available binary search trees." << endl;
        cout << "5. Operate with binary heaps." << endl;
        cout << "6. Operate with binary search tree." << endl;
        cout << "7. Launch tests." << endl;
        cout << "8. Exit." << endl;

        int point = GetInt(1, 8);

        if (point == 8)
            break;
        switch (point) {
        case 1:
            chooseBinaryHeapType(&binaryHeapIntArray, &binaryHeapFloatArray);
            break;
        case 2:
            chooseBinarySearchTreeType(&binarySearchFloatArray, &binarySearchIntArray);
            break;
        case 3:
            showAvailableBinaryHeaps(&binaryHeapIntArray, &binaryHeapFloatArray);
            break;
        case 4:
            showAvailableBinaryTrees(&binarySearchFloatArray, &binarySearchIntArray);
            break;
        case 5:
            operateWithBinaryHeaps(&binaryHeapIntArray, &binaryHeapFloatArray);
            break;
        case 6:
            operateWithBinarySearchTree(&binarySearchFloatArray, &binarySearchIntArray);
            break;
        case 7:
            tests(10);
            break;
        default:
            break;
        }
    }
}
