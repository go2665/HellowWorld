#include "BinarySearchTree.h"
#include <cstdio>

BinarySearchTree::~BinarySearchTree()
{
    DestroyTree(Root);
}

void BinarySearchTree::Insert(int InKey)
{
    Root = InsertNode(Root, InKey);
}

void BinarySearchTree::Delete(int InKey)
{
    Root = DeleteNode(Root, InKey);
}

TreeNode* BinarySearchTree::Search(int InKey)
{
    return SearchNode(Root, InKey);
}

void BinarySearchTree::PrintPreOrder() const
{
    printf("PreOrder : ");
    PreOrderTraversal(Root);
    printf("\n");
}

void BinarySearchTree::PrintInOrder() 
{
}

void BinarySearchTree::PrintPostOrder() 
{
}

TreeNode* BinarySearchTree::InsertNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return new TreeNode(InKey); // 서브루트가 null이면 그곳에 새 노드 만들어서 연결되게 하기
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = InsertNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key)
    {
        InNode->Right = InsertNode(InNode->Right, InKey);
    }
    //else
    //{
    //    // 트리에서는 키가 중복되면 안됨.
    //    // 중복된 키는 무시
    //}

    return InNode;
}

TreeNode* BinarySearchTree::DeleteNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return InNode;
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = DeleteNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key)
    {
        InNode->Right = DeleteNode(InNode->Right, InKey);
    }
    else
    {
        // 삭제할 노드를 찾았다.
        if (InNode->Left == nullptr)
        {
            // 왼쪽 자식이 없다. 자식이 둘 다 없다.
            TreeNode* Temp = InNode->Right;
            delete InNode;
            return Temp;
        }
        else if (InNode->Right == nullptr)
        {
            // 오른쪽 자식만 없다.
            TreeNode* Temp = InNode->Left;
            delete InNode;
            return Temp;
        }

        // 두 자식이 모두 있다. -> 오른쪽 서브트리의 최소값으로 대체
        TreeNode* Temp = FindMinNode(InNode->Right);
        InNode->Key = Temp->Key;
        InNode->Right = DeleteNode(InNode->Right, Temp->Key);
    }
    return InNode;
}

TreeNode* BinarySearchTree::SearchNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return nullptr; // 못찾았다.
    }

    if (InKey < InNode->Key)
    {
        return SearchNode(InNode->Left, InKey);     // 찾는 중
    }
    else if (InKey > InNode->Key)
    {
        return SearchNode(InNode->Right, InKey);    // 찾는 중
    }
    else
    {
        return InNode;  // 찾았다.
    }
}

TreeNode* BinarySearchTree::FindMinNode(TreeNode* InNode)
{
    while (InNode != nullptr && InNode->Left != nullptr)
    {
        InNode = InNode->Left;
    }
    return InNode;
}

void BinarySearchTree::PreOrderTraversal(const TreeNode* InNode) const
{
    if (InNode != nullptr)
    {
        printf("%d ", InNode->Key);
        PreOrderTraversal(InNode->Left);
        PreOrderTraversal(InNode->Right);
    }
}

void BinarySearchTree::InOrderTraversal(TreeNode* InNode)
{
}

void BinarySearchTree::PostOrderTraversal(TreeNode* InNode)
{
}

void BinarySearchTree::DestroyTree(TreeNode* InNode)
{
    if (InNode != nullptr)
    {
        DestroyTree(InNode->Left);  // 왼쪽 서브트리 삭제하고
        DestroyTree(InNode->Right); // 오른쪽 서브트리 삭제하고 
        delete InNode;  // 나를 지워라(후위순회하며 삭제하기)
    }
}
