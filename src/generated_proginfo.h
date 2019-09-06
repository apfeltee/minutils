#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/
extern int miniprog_basename_main(int argc, char** argv, char** envp);
extern int miniprog_cat_main(int argc, char** argv, char** envp);
extern int miniprog_chmod_main(int argc, char** argv, char** envp);
extern int miniprog_chown_main(int argc, char** argv, char** envp);
extern int miniprog_cmp_main(int argc, char** argv, char** envp);
extern int miniprog_cp_main(int argc, char** argv, char** envp);
extern int miniprog_dirname_main(int argc, char** argv, char** envp);
extern int miniprog_echo_main(int argc, char** argv, char** envp);
extern int miniprog_env_main(int argc, char** argv, char** envp);
extern int miniprog_false_main(int argc, char** argv, char** envp);
extern int miniprog_getloadavg_main(int argc, char** argv, char** envp);
extern int miniprog_head_main(int argc, char** argv, char** envp);
extern int miniprog_id_main(int argc, char** argv, char** envp);
extern int miniprog_kill_main(int argc, char** argv, char** envp);
extern int miniprog_ln_main(int argc, char** argv, char** envp);
extern int miniprog_ls_main(int argc, char** argv, char** envp);
extern int miniprog_mkdir_main(int argc, char** argv, char** envp);
extern int miniprog_mkfifo_main(int argc, char** argv, char** envp);
extern int miniprog_mknod_main(int argc, char** argv, char** envp);
extern int miniprog_mktemp_main(int argc, char** argv, char** envp);
extern int miniprog_mv_main(int argc, char** argv, char** envp);
extern int miniprog_nice_main(int argc, char** argv, char** envp);
extern int miniprog_nl_main(int argc, char** argv, char** envp);
extern int miniprog_nohup_main(int argc, char** argv, char** envp);
extern int miniprog_printenv_main(int argc, char** argv, char** envp);
extern int miniprog_printf_main(int argc, char** argv, char** envp);
extern int miniprog_pwd_main(int argc, char** argv, char** envp);
extern int miniprog_readlink_main(int argc, char** argv, char** envp);
extern int miniprog_realpath_main(int argc, char** argv, char** envp);
extern int miniprog_rev_main(int argc, char** argv, char** envp);
extern int miniprog_rm_main(int argc, char** argv, char** envp);
extern int miniprog_rmdir_main(int argc, char** argv, char** envp);
extern int miniprog_seq_main(int argc, char** argv, char** envp);
extern int miniprog_shred_main(int argc, char** argv, char** envp);
extern int miniprog_shuf_main(int argc, char** argv, char** envp);
extern int miniprog_sleep_main(int argc, char** argv, char** envp);
extern int miniprog_sort_main(int argc, char** argv, char** envp);
extern int miniprog_stat_main(int argc, char** argv, char** envp);
extern int miniprog_strings_main(int argc, char** argv, char** envp);
extern int miniprog_sync_main(int argc, char** argv, char** envp);
extern int miniprog_tee_main(int argc, char** argv, char** envp);
extern int miniprog_test_main(int argc, char** argv, char** envp);
extern int miniprog_timeout_main(int argc, char** argv, char** envp);
extern int miniprog_touch_main(int argc, char** argv, char** envp);
extern int miniprog_true_main(int argc, char** argv, char** envp);
extern int miniprog_truncate_main(int argc, char** argv, char** envp);
extern int miniprog_tty_main(int argc, char** argv, char** envp);
extern int miniprog_uname_main(int argc, char** argv, char** envp);
extern int miniprog_uniq_main(int argc, char** argv, char** envp);
extern int miniprog_unlink_main(int argc, char** argv, char** envp);
extern int miniprog_uptime_main(int argc, char** argv, char** envp);
extern int miniprog_wc_main(int argc, char** argv, char** envp);
extern int miniprog_which_main(int argc, char** argv, char** envp);
extern int miniprog_whoami_main(int argc, char** argv, char** envp);
extern int miniprog_yes_main(int argc, char** argv, char** envp);
/* end of prototypes */
static miniproginfo_t miniprogdefinitions[] =
{
    {"basename", "src/progs/basename.c", miniprog_basename_main},
    {"cat", "src/progs/cat.c", miniprog_cat_main},
    {"chmod", "src/progs/chmod.c", miniprog_chmod_main},
    {"chown", "src/progs/chown.c", miniprog_chown_main},
    {"cmp", "src/progs/cmp.c", miniprog_cmp_main},
    {"cp", "src/progs/cp.c", miniprog_cp_main},
    {"dirname", "src/progs/dirname.c", miniprog_dirname_main},
    {"echo", "src/progs/echo.c", miniprog_echo_main},
    {"env", "src/progs/env.c", miniprog_env_main},
    {"false", "src/progs/false.c", miniprog_false_main},
    {"getloadavg", "src/progs/getloadavg.c", miniprog_getloadavg_main},
    {"head", "src/progs/head.c", miniprog_head_main},
    {"id", "src/progs/id.c", miniprog_id_main},
    {"kill", "src/progs/kill.c", miniprog_kill_main},
    {"ln", "src/progs/ln.c", miniprog_ln_main},
    {"ls", "src/progs/ls.c", miniprog_ls_main},
    {"mkdir", "src/progs/mkdir.c", miniprog_mkdir_main},
    {"mkfifo", "src/progs/mkfifo.c", miniprog_mkfifo_main},
    {"mknod", "src/progs/mknod.c", miniprog_mknod_main},
    {"mktemp", "src/progs/mktemp.c", miniprog_mktemp_main},
    {"mv", "src/progs/mv.c", miniprog_mv_main},
    {"nice", "src/progs/nice.c", miniprog_nice_main},
    {"nl", "src/progs/nl.c", miniprog_nl_main},
    {"nohup", "src/progs/nohup.c", miniprog_nohup_main},
    {"printenv", "src/progs/printenv.c", miniprog_printenv_main},
    {"printf", "src/progs/printf.c", miniprog_printf_main},
    {"pwd", "src/progs/pwd.c", miniprog_pwd_main},
    {"readlink", "src/progs/readlink.c", miniprog_readlink_main},
    {"realpath", "src/progs/realpath.c", miniprog_realpath_main},
    {"rev", "src/progs/rev.c", miniprog_rev_main},
    {"rm", "src/progs/rm.c", miniprog_rm_main},
    {"rmdir", "src/progs/rmdir.c", miniprog_rmdir_main},
    {"seq", "src/progs/seq.c", miniprog_seq_main},
    {"shred", "src/progs/shred.c", miniprog_shred_main},
    {"shuf", "src/progs/shuf.c", miniprog_shuf_main},
    {"sleep", "src/progs/sleep.c", miniprog_sleep_main},
    {"sort", "src/progs/sort.c", miniprog_sort_main},
    {"stat", "src/progs/stat.c", miniprog_stat_main},
    {"strings", "src/progs/strings.c", miniprog_strings_main},
    {"sync", "src/progs/sync.c", miniprog_sync_main},
    {"tee", "src/progs/tee.c", miniprog_tee_main},
    {"test", "src/progs/test.c", miniprog_test_main},
    {"timeout", "src/progs/timeout.c", miniprog_timeout_main},
    {"touch", "src/progs/touch.c", miniprog_touch_main},
    {"true", "src/progs/true.c", miniprog_true_main},
    {"truncate", "src/progs/truncate.c", miniprog_truncate_main},
    {"tty", "src/progs/tty.c", miniprog_tty_main},
    {"uname", "src/progs/uname.c", miniprog_uname_main},
    {"uniq", "src/progs/uniq.c", miniprog_uniq_main},
    {"unlink", "src/progs/unlink.c", miniprog_unlink_main},
    {"uptime", "src/progs/uptime.c", miniprog_uptime_main},
    {"wc", "src/progs/wc.c", miniprog_wc_main},
    {"which", "src/progs/which.c", miniprog_which_main},
    {"whoami", "src/progs/whoami.c", miniprog_whoami_main},
    {"yes", "src/progs/yes.c", miniprog_yes_main},
    {{}, {}, NULL}
};
#if defined(__cplusplus)
} /* extern "C" */ 
#endif /* __cplusplus*/
