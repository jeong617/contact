import org.opentutorials.iot.Security;
import org.opentutorials.iot.Elevator;
import org.opentutorials.iot.Lighting;

public class OkJavaGoInHome {

	public static void main(String[] args) {
		
		// 내가 해야 할 일?
		// 집에 갈 때 반복적으로 하는 일들을 java한테 시키고싶어!
		
		String id = "JAVA APT 507";
		
		// Elevator call
		Elevator myElevator = new Elevator(id);
		myElevator.callForUp(1); // 1층으로 엘리베이터 보내!
		
		// Security off
		Security mySecurity = new Security(id);
		mySecurity.off();
		
		// Light on
		Lighting hallLamp = new Lighting(id);
		hallLamp.on();
		
		Lighting floorLamp = new Lighting(id);
		floorLamp.on();
	}
}
