#include <iostream>

#ifndef TREE_H
#define TREE_H

struct Node {
    std::shared_ptr<Node> left, right;

    int id;

    std::string value;

    int height;

    Node(int id, std::string v) : id(id), value(std::move(v)) {
        height = 1;
        right = left = nullptr;
    }
};

class Tree {
public:
    std::shared_ptr<Node> root;

    Tree() : root(nullptr) {};

    void insert(int id, const std::string &value) {
        root = insert(root, id, value);
    }

    void remove(int id) {
        root = remove(root, id);
    }

    void print() {
        print(root);
    }

    void print_r() {
        print_r(root);
    }

    int find_node_with_one_child() {
        return find_node_with_one_child(root);
    }

    void from_array(int *arr, int n) {
        for(int i = 0; i < n; i++) {
            insert(arr[i], QString::number(arr[i]).toStdString());
        }
    }

    void update_tree(QTreeWidget *tree) {
        tree->clear();
        if (root != nullptr) {
            auto *item = new QTreeWidgetItem(tree);
            item->setText(0, QString::number(root->id));
            item->setText(1, QString::fromStdString(root->value));
            tree->addTopLevelItem(item);

            if (root->left) {
                update_tree(item, root->left);
            }
            if (root->right) {
                update_tree(item, root->right);
            }
        }
    }


private:

    static int height(const std::shared_ptr<Node> &p) {
        return p ? p->height : 0;
    }

    static int b_factor(const std::shared_ptr<Node> &p) {
        return height(p->right) - height(p->left);
    }

    static void fix_height(std::shared_ptr<Node> &p) {
        int hl = height(p->left);
        int hr = height(p->right);
        p->height = (hl > hr ? hl : hr) + 1;
    }

    static std::shared_ptr<Node> rotate_right(std::shared_ptr<Node> &p) {
        std::shared_ptr<Node> q = p->left;
        p->left = q->right;
        q->right = p;
        fix_height(p);
        fix_height(q);
        return q;
    }

    static std::shared_ptr<Node> rotate_left(std::shared_ptr<Node> &q) {
        std::shared_ptr<Node> p = q->right;
        q->right = p->left;
        p->left = q;
        fix_height(q);
        fix_height(p);
        return p;
    }

    static std::shared_ptr<Node> balance(std::shared_ptr<Node> &p) {
        fix_height(p);
        if (b_factor(p) == 2) {
            if (b_factor(p->right) < 0) {
                p->right = rotate_right(p->right);
            }
            return rotate_left(p);
        }

        if (b_factor(p) == -2) {
            if (b_factor(p->left) > 0) {
                p->left = rotate_left(p->left);
            }
            return rotate_right(p);
        }
        return p;
    }

    std::shared_ptr<Node> insert(std::shared_ptr<Node> &p, int id, const std::string &value) {
        if (!p) {
            return std::make_shared<Node>(id, value);
        }

        if (id < p->id) {
            p->left = insert(p->left, id, value);
        } else if (id > p->id) {
            p->right = insert(p->right, id, value);
        } else {
            p->value = value;
        }
        return balance(p);
    }

    std::shared_ptr<Node> find_min(std::shared_ptr<Node> &p) {
        return p->left ? find_min(p->left) : p;
    }

    std::shared_ptr<Node> remove_min(std::shared_ptr<Node> &p) {
        if (p->left == nullptr) {
            return p->right;
        }

        p->left = remove_min(p->left);

        return balance(p);
    }

    std::shared_ptr<Node> remove(std::shared_ptr<Node> &p, int id) {
        if (!p) {
            return nullptr;
        }
        if (id < p->id) {
            remove(p->left, id);
        } else if (id > p->id) {
            p->right = remove(p->right, id);
        } else {
            std::shared_ptr<Node> q = p->left;
            std::shared_ptr<Node> r = p->right;
            p = nullptr;
            if (!r) return q;
            std::shared_ptr<Node> min = find_min(r);
            min->right = remove_min(r);
            min->left = q;
            return balance(min);
        }
        return balance(p);
    }

    void print(std::shared_ptr<Node> &p) {
        std::cout << p->id << "\t" << p->value << "\n";
        if (p->left) {
            std::cout << "Go left\n";
            print(p->left);
        }
        if (p->right) {
            std::cout << "Go right\n";
            print(p->right);
        }
        std::cout << "Go back\n";
    }

    void print_r(std::shared_ptr<Node> &p) {

        if (p->left) {
            std::cout << "Go left\n";
            print_r(p->left);
        }
        if (p->right) {
            std::cout << "Go right\n";
            print_r(p->right);
        }
        std::cout << p->id << "\t" << p->value << "\n";
        std::cout << "Go back\n";
    }

    int find_node_with_one_child(std::shared_ptr<Node> &p) {
        if(p == nullptr) return 0;
        int ans = 0;
        if (p->left) {
            if (!p->right) ans++;
            ans += find_node_with_one_child(p->left);
        }
        if (p->right) {
            if (!p->left) ans++;
            ans += find_node_with_one_child(p->right);
        }
        return ans;
    }

    void update_tree(QTreeWidgetItem *parent, std::shared_ptr<Node> &p) {
        auto *item = new QTreeWidgetItem(parent);
        item->setText(0, QString::number(p->id));
        item->setText(1, QString::fromStdString(p->value));
        parent->addChild(item);
        if (p->left) {
            update_tree(item, p->left);
        }
        if (p->right) {
            update_tree(item, p->right);
        }
    }
};

#endif
