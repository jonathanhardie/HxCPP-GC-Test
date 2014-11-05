package;
import cpp.Pointer;
import cpp.Float32;
import cpp.Lib;
import cpp.vm.Gc;
class TestGC {

	var handle:Pointer<Float32>;
	var child:ChildObj;

	static var test:TestGC;

	public function new() {
		// This handle is not collected
		trace('new handle that top level obj holds');
		handle = getExternalHandle();

		// This handle is collected
		trace('new child');
		child = new ChildObj();
		//child = null;
		trace("--GC run--");
		Gc.run(true);

		// Even setting this handle to null doesn't cause it to be collected.
		trace('nulling handle held by top level obj');
		handle = null;

		trace("--GC run--");
		Gc.run(true);
	}

	public static function main() {
		test = new TestGC();
	}

	public static var getExternalHandle:Void->Pointer<Float32> = Lib.load("test", "allocateMatrix", 0);
}

class ChildObj {
	public function new() {
		handle = TestGC.getExternalHandle();
	}
	var handle:Pointer<Float32>;
}
