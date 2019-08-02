#include <vector>
#include <iostream>

const int MAX_LEVEL = 4;
const double prob = 0.5;

class Node {
 private:
    int level;
    int value;
    std::vector<Node*> next;
    friend class Skip;
 public:
    Node(int level1, int value1) :level(level1), value(value1) {}
};

class Skip {
 private:
    Node* header;
 public:
    Skip();
    void insert_node(int value, int level);
    void print_list();
};

Skip::Skip() {
    header = new Node(MAX_LEVEL, -1);
    for (int i = 0; i < MAX_LEVEL; ++i)
        (header->next).push_back(nullptr);
}

void Skip::insert_node(int value, int level) {
    // TODO(gadi): fix this, just wanted to manually add after header
    Node* node = new Node(level, value);
    for (int i = 0; i < node->level; ++i) {
        (node->next).push_back((header->next)[i]);
        (header->next)[i] = node;
    }
}

void Skip::print_list() {
    Node* node;
    for (int i = MAX_LEVEL-1; i >= 0; --i) {
        node = header;
        while ((node->next)[i] != nullptr) {
        // TODO(gadi): will i miss the last node?
            node = (node->next)[i];
            std::cout << node->value << '\t';
        }
        std::cout << '\n';
    }
}

int main() {
    Skip sl;
    sl.insert_node(10, 2);
    sl.insert_node(20, 3);
    sl.insert_node(30, 1);
    sl.print_list();
    return 0;
}
