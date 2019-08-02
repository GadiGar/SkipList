#include <vector>
#include <iostream>
#include <time.h>

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
    Node* find_position(int val, int level);
    int rand_level();
 public:
    Skip();
    void insert_node(int value);
    void print_list();
};

Skip::Skip() {
    header = new Node(MAX_LEVEL, -1);
    for (int i = 0; i < MAX_LEVEL; ++i)
        (header->next).push_back(nullptr);
    srand(time(NULL));
}

Node* Skip::find_position(int val, int level) {
    Node* pos = header;
    while ((pos->next[level]) != nullptr)
        if ((pos->next)[level]->value < val)
            pos = (pos->next)[level];
        else
            break;
    return pos;
}

int Skip::rand_level() {
    int level = 0;
    while (level < MAX_LEVEL-1) {
        int my_rand = rand() % 100;
        // std::cout << my_rand << '\t';
        if (my_rand > static_cast<int>(prob * 100))
            ++level;
        else
            break;
    }
    std::cout << '\n';
    return level+1;
}

void Skip::insert_node(int value) {
    int level = rand_level();
    Node* node = new Node(level, value);
    Node* prev;
    std::cout << "next val will be " << value << " with level " << level << '\n';
    for (int i = 0; i < node->level; ++i) {
        prev = find_position(value, i);
        (node->next).push_back((prev->next)[i]);
        (prev->next)[i] = node;
    }
    std::cout << "insert value " << value << " after " << prev->value
        << " with level " << level << '\n';
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
    for (int i = 0; i < 20; ++i) {
        sl.insert_node(rand() % 100);
    }
    sl.print_list();
    return 0;
}
