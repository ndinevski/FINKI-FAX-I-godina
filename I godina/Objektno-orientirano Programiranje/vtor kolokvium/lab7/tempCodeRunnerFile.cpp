double VkupnaPlata(){
            double vk=0;
            for(int i=0;i<vraboteni;i++){
                vk+=employees[i]->plata();
            }
            return vk;
        }
        double filtriranaPlata(Employee * emp){

        }