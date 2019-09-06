#!/usr/bin/ruby -w

require "pathname"

PROTOTEMPLATE = "miniprog_%s_main"

def printcpphead(ofh)
  ofh.puts(
    "#if defined(__cplusplus)\n" +
    "extern \"C\" {\n" +
    "#endif /* __cplusplus*/\n"
  )
end

def printcppfoot(ofh)
  ofh.puts(
    "#if defined(__cplusplus)\n" +
    "} /* extern \"C\" */ \n" +
    "#endif /* __cplusplus*/\n"
  )
end

begin
  selfabsdir = File.absolute_path(__dir__)
  ofile = File.join(selfabsdir, "src", "generated_proginfo.h")
  progdir = File.join(selfabsdir, "src", "progs")
  File.open(ofile, "wb") do |ofh|
    buf = {}
    printcpphead(ofh)
    Dir.each_child(progdir) do |item|
      fullpath = File.join(progdir, item)
      next unless File.file?(fullpath)
      next unless item.match?(/\.c$/)
      relpath = Pathname.new(fullpath).relative_path_from(Pathname.new(selfabsdir))
      stem = File.basename(item, ".c")
      buf[stem] = relpath.to_s
      $stderr.printf("found %p ...\n", relpath.to_s)
      #ofh.printf("MINIMAKEDEFINITION(%s, %p);\n", stem, relpath.to_s);
      ofh.printf("extern int %s(int argc, char** argv, char** envp);\n", sprintf(PROTOTEMPLATE, stem));
    end
    ofh.printf("/* end of prototypes */\n");
    ofh.printf("static miniproginfo_t miniprogdefinitions[] =\n{\n");
    buf.each do |name, path|
      ofh.printf("    {%p, %p, %s},\n", name, path, sprintf(PROTOTEMPLATE, name));
    end
    ofh.printf("    {{}, {}, NULL}\n");
    ofh.printf("};\n");
    printcppfoot(ofh)
  end
end


