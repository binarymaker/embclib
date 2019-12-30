import os

project_loc = 3 ###

custom_lint_dir = os.getcwd()
project_dir = os.path.join(custom_lint_dir,'../'* project_loc)
project_dir = os.path.abspath(project_dir)

print('Project folder     -', project_dir)
print('Lint config folder -', custom_lint_dir)

fle = open('lint-config.lnt', 'w+')

fle.write("-setenv(PROJECT_DIR=\"%s\")\n" %project_dir)
fle.write("-setenv(CUSTOM_LINT_DIR=\"%s\")\n" %custom_lint_dir)
fle.write("%CUSTOM_LINT_DIR%\lint-settings.lnt\n")

fle.close()