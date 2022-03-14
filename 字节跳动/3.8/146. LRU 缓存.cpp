//
//  146. LRU 缓存.cpp
//  字节跳动
//
//  Created by SSR on 2022/3/8.
//

#include <stdio.h>
#include <unordered_map>
using namespace::std;

struct DLinkedNode {
    int key, value;// 键对值
    DLinkedNode* prev;// 前一个
    DLinkedNode* next;// 后一个
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}// 无数创建
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}// 给键值创建
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;// 哈希
    DLinkedNode* head;// 当更新一个数据时，需要加入头部
    DLinkedNode* tail;// 当挤出一个数据时，需要删除尾部
    int size;// 需要长度去确定
    int capacity;// 最长缓存，O(capaceity)内存空间

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 创建使用伪头部和伪尾部节点，保证必有头和尾
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    // get方法，需要更新数据
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    // put方法，可能要挤出数据
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

int main() {
    
    return 0;
}
