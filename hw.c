#include <linux/module.h>
#include <linux/sched/signal.h>	//for_each_process()
#include <linux/kernel.h>
#include <linux/proc_fs.h>

int __init my_init(void){
    /*,
    * Tasks are stored in a doubly linked list
    * in order to access them we allocate a pointer 
    * to a task struct
    */
    struct task_struct *proc =current;
    struct task_struct *parent_task = proc->parent;

    size_t pCount = 0;

    for_each_process(proc){

        printk("Name: %-15s |PID: %5d |State: %5lu |Priority: %5u|Parent: %5s \n Parent PPID: %5d", proc->comm, proc->pid, proc->state,proc->prio, parent_task->comm, parent_task->pid);
  	++pCount;
    }
    printk(KERN_INFO"\n Total Process: %zu\n", pCount);
    return 0;
}

void my_exit(void){
	printk("Exit Module");
}

module_init(my_init);
module_exit(my_exit);
