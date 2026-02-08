template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    // TODO
    Node* newNode = new Node(elem);

    if(isEmpty()) {
        head = newNode; 
    } else {
        Node* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
    Node* curr = head; 
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
    this->length = 0; 
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("getElement error: position out of range"); 
    }

    Node* curr = head; 
    for(int i=0; i < position; i++) {
        curr = curr->next;
    }
    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}



template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("replace error: position out of range"); 
    }
    Node* curr = head; 
    for(int i = 0; i < position; i++) {
        curr = curr->next;
    }
    curr->value = elem;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if(position < 0|| position > this->length) {
        throw string("insert error: position out of range"); 
    }


    Node* newNode = new Node(elem); 

    if (position == 0) {
        newNode->next = head; 
        head = newNode; 
        this->length++; 
        return;
    }

    Node* prev = head; 
    for (int i = 0; i < position - 1; i++) {
        prev = prev->next;
    }

    newNode->next = prev->next;
    prev->next = newNode;
    this->length++;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if(isEmpty()) {
        throw string("remove error: list is empty");
    }
    if (position < 0 || position >= this->length) {
        throw string("remove error: position out of range");
    }

    if (position == 0) {
        Node* temp = head; 
        head = head->next;
        delete temp; 
        this->length--;
        return;
    }

    Node* prev = head; 
    for (int i=0; i < position - 1; i++) {
        prev = prev->next;
    }
    
    Node* victim = prev->next;
    prev->next = victim->next;
    delete victim; 
    this->length--; 
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
