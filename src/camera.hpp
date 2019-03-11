//
// Created by nikjan on 3/11/19.
//

#ifndef RG165_BETHEBACHELOR_CAMERA_H
#define RG165_BETHEBACHELOR_CAMERA_H 1


class Camera {
public:
    Camera(double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ, double upX,
           double upY, double upZ);
    Camera() {

    }

    void setLook(int id);

    void setEyeX(double eyeX);

    void setEyeY(double eyeY);

    void setEyeZ(double eyeZ);

    void setCenterX(double centerX);

    void setCenterY(double centerY);

    void setCenterZ(double centerZ);

    void setUpX(double upX);

    void setUpY(double upY);

    void setUpZ(double upZ);

private:
    double eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ;
};


#endif //RG165_BETHEBACHELOR_CAMERA_H
