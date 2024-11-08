tss_t* obtener_TSS(unit_16_t segsel){
   uint_16_t idx = segsel >> 3;
   
   // (estp en realidad se guarda de a partes en la GTD entry)
   return gdt[idx].base;
}


uint_8_t es_prioritaria(uint_8_t i){
   tss_t* tss_task = obtener_TSS(sched_task[i].selector)
   uint32_t* pila = tss_task->esp;
   uint32_t edx = pila[5];
   return edx == 0x00FAFAFA;
}

static sched_entry_t sched_task[MAX_TASKS] = {0}
int8_t current_task = 0;
int8_t last_task_priority = 0;
int8_t last_task_no_priority = 0;

uint_16_t sched_next_task(void){
// Buscamos la proxima tarea viva con prioridad
   for(i = (last_task_priority+1); (i % MAX_TASKS) != last_task_no_priority; i++){
      if (sched_task[i % MAX_TASKS].state == TASK_RUNNABLE && es_prioritaria(i)) break;
   }

// A la salida:
//  - i != last_task_priority: mas de una tarea prioritaria
//  - i == last_task_priority == current_task, no quiero repetir
//  - i != last_task_priority != current_task,
//  ultima no fue prioritaria
//  Ajustamos i para que este entre 0 y MAX_TASKS-1

   i = i % MAX_TASKS;
   if (i != current_task && es_prioritaria(i)){
      // Hay mas de una tarea prioritaria + viva
      // o la ultima tarea ejecutada fue sin prioridad
      last _task_priority = i;
      current_task = i;
      for( i = (last_task_no_priority + 1) ; (i% MAX_TASKS)!= last_task_no_priority_no_priority; i++){
         if (sched_tasks[i % MAX_TASKS].state == TASK_RUNNABLE) break;
      }
   return sched_tasks[i].selector;
   }

// Si llegue aca es porque
// - La ultima tarea ejecutada fue
// con prioridad (y hay solo una con prioridad)
// - o no hay con prioridad
// - o no hay mas tareas vivas

   if (sched_task[i].state == TASK_RUNNABLE){
   // Si llegamos aca, la tarea que encontramos
   // no es prioritaria
      last_task_no_priority = i;
      current_task = i;
      return sched_tasks[i].selector;
   }

// En el peor de los casos no hay ninguna tarea viva
// Usemos la idle como selector.
   return GDT_IDX_TASK << 3;
}
