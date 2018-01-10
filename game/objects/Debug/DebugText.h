//
// Created by Sophie Gauthier on 08/01/2018.
//

#ifndef SILLYGAME2_DEBUGTEXT_H
#define SILLYGAME2_DEBUGTEXT_H


#include <object/GameObject.h>

class DebugText : public GameObject
{
protected:
    std::shared_ptr<Object> m_text;
public:
    void onInstance() override;

    void onUpdate() override;

};


#endif //SILLYGAME2_DEBUGTEXT_H
