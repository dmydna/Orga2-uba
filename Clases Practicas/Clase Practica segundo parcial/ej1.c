int espiar(uint16_t selector, uint32_t* direccion_a_espiar, uint32_t* direccion_a_escribir){
   // TO DO
   uint32_t cr3_tarea_a_espiar = obtenerCR3(selector);
   
   // Guardo el cr3 actual
   uint32_t cr3_tarea_espia = rcr3();
   
   // TO DO
   paddr_t direccion_fisica_a_espiar = obtenerDireccionFisica(cr3_tarea_a_espiar,direccion_a_espiar);


   if (direccion_fisica_a_espiar == 0) return 1;
   // Falló si la dirección de memoria no era válida

   mmu_map_page(cr3_tarea_espia, SRC_VIRT_PAGE, direccion_fisica_a_espiar)
   // TO DO
   /*Nota: Acá usé SRC_VIRT_PAGE definida en copy_page()
   Podría usar otra dirección virtual pero es importante usar una reservada 
   para no pisar un mapeo válido */
   
   //Como 4 bytes son 32 bits me alcanza con una variable :D
   uint32_t dato_a_copiar = *((SRC_VIRT_PAGE & 0xFFFFFF000) | VIRT_PAGE_OFFSET(direccion_a_espiar));
   
   //IMPORTANTE no olvidar el offset!
   
   mmu_unmap_page(cr3_tarea_espia, SRC_VIRT_PAGE,direccion_fisica_a_espiar);

   direccion_a_escribir[0] = dato_a_copiar;

   return 0;
}


uint32_t obtenerDireccionFisica(uint32_t cr3_tarea_a_espiar, uint32_t* direccion_a_espiar){
   //Nos inspiramos en las funciones de map_page y unmap_page
   pd_entry_t* pd = (pd_entry_t*)CR3_TO_PAGE_DIR(cr3_tarea_a_espiar);
   
   int pdi = VIRT_PAGE_DIR(direccion_a_espiar);
   if(!(pd[pdi].attrs & MMU_P)) return 0;

   pt_entry_t* pt = (pt_entry_t)MMU_ENTRY_PADDR(pd[pdi].pt);
   int pti = VIRT_PAGE_TABLE(direccion_a_espiar);

   if(!(pt[pti].attrs & MMU_P)) return 0;

   paddr_t direccion_fisica = MMU_ENTRY_PADDR(pt[pti].page);

   // Hasta aca es CASI IGUAL a mmu_unmap_page (solo cambie nombre de variables), ahora en vez de poner el presente en 0, solo devuelvo la direccion fisica

   return direccion_fisica //OJO esto devuelve la BASE de la página a la que apuntaba la dirección física (sin el offset

}


