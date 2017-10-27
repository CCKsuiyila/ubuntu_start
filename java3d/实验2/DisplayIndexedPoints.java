import java.applet.Applet;
import java.awt.*;
import com.sun.j3d.utils.applet.MainFrane;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;
import javax.media.j3d.*;
import javax.vecmath.*;

public class DisplayIndexedPoints extends Applet{
    public BranchGroup createBranchGroup(){
        BranchGroup BranchGroupRoot=new BranchGroup();
        BoundingSphere bounds=new BoundingSphere(new Point3d(0.0,0.0,0.0),100.0);
        Color3f bgColor=new Color3f(1.0f,1.0f,1.0f);
        Background bg=new Background(bgColor);
        bg.setApplicationBounts(bounds);
        BranchGroupRoot.addChild(bg);
        TransformGroup transformgroup=new TransformGroup();
        transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        BranchGroupRoot.addChild(transformgroup);
        MouseRotate mouserotate=new MouseRotate();
        mouserotate.setTransformGroup(transformgroup);
        BranchGroupRoot.addChild(mouserotate);
        mouserotate.setSchedulingVounds(bounds);
        MouseZoom mousezoom=newMouseZoom();
        mousezoom.setTransformGroup(transformgroup);
        BranchGroupRoot.addChild(mousezoom);
        mousezoom.setSchedulingBounds(bounds);
        MouseTranslate mousetranslate=new MouseTranslate();
        mousetranslate.setTransformGroup(transformgroup);
        BranchGroupRoot.addChild(mousetranslate);
        mousetranslate.setSchedulingBounds(bounds);
        Shape3D shapepoints=new Shape3D();
        //define the coordinates of the vertexes

    }
}
