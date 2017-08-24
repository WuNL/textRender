#ifndef TEXTRENDER_H
#define TEXTRENDER_H
// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// FreeType
#include <ft2build.h>
#include FT_FREETYPE_H
// GL includes
#include "Shader.h"
#include <locale>
#include <codecvt>

#include <iostream>
#include <map>
/// Holds all state information relevant to a character as loaded using FreeType
struct Character
{
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
    GLuint Advance;    // Horizontal offset to advance to next glyph
};


class textRender
{
public:
    textRender(int window_width, int window_height, const char* path);
    virtual ~textRender();
    void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
    void fillChar(wchar_t c);
protected:

private:
    Shader shader;
    FT_Library ft;
    FT_Face face;

    GLuint VAO, VBO;

    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    std::map<wchar_t, Character> Characters;
};

#endif // TEXTRENDER_H
