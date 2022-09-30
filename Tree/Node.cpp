#include "Node.h"

char* Node::GetEnglish()
{
    return m_english;
}

char* Node::GetRussian()
{
    return m_russian;
}

void Node::SetEnglish(char* str) {
    for (int i = 0; i < 15; i++) {
        m_english[i] = str[i];
    }
}