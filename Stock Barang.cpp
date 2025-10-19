#include <iostream>
using namespace std;

struct Node {
    int kode, stok;
    Node *left, *right;
    Node(int k, int s) : kode(k), stok(s), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int kode, int stok) {
    if (root == NULL) {
        return new Node(kode, stok);
    }
    if (kode < root->kode) {
        root->left = insertNode(root->left, kode, stok);
    }
    else if (kode > root->kode) {
        root->right = insertNode(root->right, kode, stok);
    }
    return root;
}

Node* searchNode(Node* root, int kode) {
    if (root == NULL || root->kode == kode) {
        return root;
    }
    if (kode < root->kode)
        return searchNode(root->left, kode);
    else
        return searchNode(root->right, kode);
}

Node* minNode(Node* root) {
    Node* cur = root;
    while (cur && cur->left != NULL) cur = cur->left;
    return cur;
}

Node* deleteNode(Node* root, int kode) {
    if (root == NULL) return root;
    if (kode < root->kode) {
        root->left = deleteNode(root->left, kode);
    }
    else if (kode > root->kode) {
        root->right = deleteNode(root->right, kode);
    }
    else {
        if (root->left == NULL) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        if (root->right == NULL) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        Node* tmp = minNode(root->right);
        root->kode = tmp->kode;
        root->stok = tmp->stok;
        root->right = deleteNode(root->right, tmp->kode);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->kode << " " << root->stok << "\n";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    while (true) {
        cout << "Menu:\n";
        cout << "1 Tambah\n2 Cari\n3 Hapus\n4 Tampil\n5 Keluar\n";
        cout << "Pilihan: ";
        int pil; cin >> pil;
        if (pil == 1) {
            int k, s;
            cout << "Kode: "; cin >> k;
            cout << "Stok: "; cin >> s;
            root = insertNode(root, k, s);
        }
        else if (pil == 2) {
            int k; cout << "Kode: "; cin >> k;
            Node* res = searchNode(root, k);
            if (res != NULL) cout << res->stok << "\n";
            else cout << "0\n";
        }
        else if (pil == 3) {
            int k; cout << "Kode: "; cin >> k;
            root = deleteNode(root, k);
        }
        else if (pil == 4) {
            inorder(root);
        }
        else if (pil == 5) {
            break;
        }
    }
    return 0;
}