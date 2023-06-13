/**
 * @file Tag.hpp
 * @brief This file contains definitions for the Tag class.
 *
 * @date 2023-06-13
 * @author Willow Ciesialka
 */

#ifndef TAG_H
#define TAG_H

#include <string>
#include <iostream>

namespace GolfEngine
{
    class Tag
    {
    public:
        Tag() : name("Default"){};
        Tag(std::string tag_name) : name(tag_name){};

        /**
         * @brief Get the Tag in string format.
         * 
         * @returns The name of the tag.
        */
        inline std::string getTag() const
        {
            return this->name;
        }

        inline bool operator ==(const Tag& rhs){
            return this->getTag().compare(rhs.getTag()) == 0;
        }

        inline bool operator ==(const std::string& str){
            return this->getTag().compare(str) == 0;
        }

        inline bool operator !=(const Tag& rhs){
            return !(*this == rhs);
        }

        inline bool operator !=(const std::string& str){
            return !(*this == str);
        }

        inline friend std::ostream &operator<<(std::ostream &os, const Tag &tag)
        {
            os << "Tag(" << tag.getTag() << ")";
            return os;
        };

    private:
        std::string name;
    };
}

#endif
