**Simple Function Pass**
- Hello all llvm developers and fresher who want to learn LLVM llvm passes.
- This repository will just give a keen idea of how to right basic llvm fuction pass.

**Input for the Pass**
- This pass will take input as .ll file.

**Output**
- This pass will give output total number of function in c code and number of argument it take.


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ![Input_Output](https://github.com/aabhinavg/LLVM_Passes/blob/main/1stPass/llvm_first_pass.png)




**Steps To Start**
- Build LLVM with clang from the scratch.
- Create a directory to write llvm pass
&nbsp;&nbsp&nbsp;<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp">$ mkdir path/to/llvm/lib/FirstPass</span> 
- Update the CMake 
&nbsp;&nbsp&nbsp;<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp">$ vim path/to/llvm/lib/FirstPass/CMakeLists.txt</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ![cmake_file](https://github.com/aabhinavg/LLVM_Passes/blob/main/1stPass/Untitled%20Diagram.drawio.png)

- Update the CMake Inside Transforms folder
&nbsp;&nbsp&nbsp;<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp">$ vim path/to/llvm/lib/Transforms/CMakeLists.txt</span>
&nbsp;&nbsp&nbsp;<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp">add_subdirectory(FirstPass)</span>

**Copy FirstPass.cpp file**
**Run**
- To run see the script.sh file attached.
- ./script --help for more information
 













