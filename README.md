HxCPP-GC-Test
=============

Steps to reproduce:

1. Build exe<br>
`haxe compile-gc-test.hxml`<br>

2. Compile test.ndll and move to location of haxe exe.<br>
`g++ gctest.cpp -shared -o ./test.ndll -I${HXCPP_INCLUDE_PATH}`<br>

3. Run exe.

Output:

`TestGC.hx:15: new handle that top level obj holds`<br>
`allocating 0x10020ea70, wrapping in abstract 0x101001dbc, setting finalizer 0x1001f38c0`<br>
`TestGC.hx:19: new child`<br>
`allocating 0x10020d0d0, wrapping in abstract 0x101002014, setting finalizer 0x1001f38c0`<br>
`TestGC.hx:22: --GC run--`<br>
`freeing mem 0x10020d0d0, abstract 0x101002014`<br>
`TestGC.hx:26: nulling handle held by top level obj`<br>
`TestGC.hx:29: --GC run--`<br>
