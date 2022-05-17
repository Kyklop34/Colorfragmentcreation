void createFragment(InFragment *inFragment, triangle_t Triangle, Program prg, std::vector<double> bar, double area, int x, int y)
{

    inFragment->gl_FragCoord.x = x+0.5;
    inFragment->gl_FragCoord.y = y+0.5;

    //setting depth of inFragments
    inFragment->gl_FragCoord.z = TPOINT(0,2)*bar[0] + TPOINT(1,2)*bar[1] + TPOINT(2,2)*bar[2];
    
    double s = (bar[0]/TPOINT(0,3)) + (bar[1]/TPOINT(1,3)) + (bar[2]/TPOINT(2,3));

    bar[0] = (bar[0])/(TPOINT(0,3)*s);
    bar[1] = (bar[1])/(TPOINT(1,3)*s);
    bar[2] = (bar[2])/(TPOINT(2,3)*s);

    double res;

    for (int i = 0; i < maxAttributes; i++){
        if (prg.vs2fs[i] == AttributeType::VEC3)
        {
            for (int i = 0; i < 3; i++)
            {
                res = 0;
                for (int j = 0; j < 3; j++)
                {
                    res += bar[j] * Triangle.points[j].attributes[0].v3[i];
                }
            
                inFragment->attributes[0].v3[i] = res;     
            }
        } else if (prg.vs2fs[i] == AttributeType::VEC4)
        {
            for (int i = 0; i < 4; i++)
            {
                res = 0;
                for (int j = 0; j < 3; j++)
                {
                    res += bar[j] * Triangle.points[j].attributes[0].v4[i];
                }
            
                inFragment->attributes[0].v4[i] = res;     
            }
        }
    }
}
