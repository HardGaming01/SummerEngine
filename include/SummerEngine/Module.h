#ifndef MODULE_H
#define MODULE_H

namespace SE
{
class Module
{
public:
    virtual void startUp() = 0;
    virtual void shutDown() = 0;
    virtual void update() = 0;
};
}

#endif //MODULE_H
